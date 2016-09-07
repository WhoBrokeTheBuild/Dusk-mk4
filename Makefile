TARGET = libdusk
include make/config.mk

.PHONY: all static dynamic clean clean_deps clean_objects clean_targets \
   		install test check

# Dynamically get the sources/objects/tests

SOURCES = $(shell find $(SRC_DIR) -type f -name '*.cpp')
HEADERS = $(shell find $(SRC_DIR) -type f -name '*.hpp')
TESTS   = $(patsubst %.cpp,%,$(wildcard $(TESTS_DIR)/*_test.cpp))

AR_OBJ_DIR = $(OBJ_DIR)/static
AR_DEP_DIR = $(DEP_DIR)/static
AR_OBJECTS = $(patsubst $(SRC_DIR)/%.cpp,$(AR_OBJ_DIR)/%.o,$(SOURCES))
AR_TARGET  = $(TARGET_PATH).a

SO_OBJ_DIR = $(OBJ_DIR)/dynamic
SO_DEP_DIR = $(DEP_DIR)/dynamic
SO_OBJECTS = $(patsubst $(SRC_DIR)/%.cpp,$(SO_OBJ_DIR)/%.o,$(SOURCES))
SO_TARGET  = $(TARGET_PATH).so

# Create directories to prevent "cannot create file" errors

$(shell mkdir -p $(BUILD_DIR) $(SRC_DIR))
$(shell mkdir -p $(patsubst $(SRC_DIR)%,$(AR_DEP_DIR)%,$(dir $(SOURCES))))
$(shell mkdir -p $(patsubst $(SRC_DIR)%,$(SO_DEP_DIR)%,$(dir $(SOURCES))))
$(shell mkdir -p $(dir $(AR_OBJECTS) $(SO_OBJECTS)))

# Build the main targets

all: $(AR_TARGET) $(SO_TARGET)

$(AR_OBJ_DIR)/%.o : $(SRC_DIR)/%.cpp
$(AR_OBJ_DIR)/%.o : $(SRC_DIR)/%.cpp $(AR_DEP_DIR)/%.d
	$(CXX) $(CXXFLAGS) -MM -MP -MT $@ -o $(AR_DEP_DIR)/$*.d $<
	$(CXX) $(CXXFLAGS) -c -o $@ $<

$(SO_OBJ_DIR)/%.o : $(SRC_DIR)/%.cpp
$(SO_OBJ_DIR)/%.o : $(SRC_DIR)/%.cpp $(SO_DEP_DIR)/%.d
	$(CXX) $(CXXFLAGS) -MM -MP -MT $@ -o $(SO_DEP_DIR)/$*.d $<
	$(CXX) $(CXXFLAGS) -c -o $@ $<

$(AR_TARGET): $(AR_OBJECTS)
	$(AR) rcs $@ $^
	ranlib $@

$(SO_TARGET): CXXFLAGS  += -fPIC
$(SO_TARGET): LDFLAGS += -shared
$(SO_TARGET): $(SO_OBJECTS)
	$(CXX) $(LDFLAGS) -o $@ $^ $(LDLIBS)

# Clean dependencies, objects, or the main target

clean:
	rm -rf $(DEP_DIR) $(OBJ_DIR) $(BUILD_DIR)

clean_deps:
	rm -rf $(DEP_DIR)

clean_objects:
	rm -f $(AR_OBJECTS) $(SO_TARGETS)

clean_targets:
	rm -f $(AR_TARGET) $(SO_TARGET)

# Install to system

install: all
	install -d $(DESTDIR)/$(PREFIX)/lib/
	install $(TARGET) $(DESTDIR)/$(PREFIX)/lib/

# Format code

format:
	clang-format -style=file -i $(filter-out $(SRC_DIR)/thirdparty%,$(SOURCES)) \
		$(filter-out $(SRC_DIR)/thirdparty%,$(HEADERS))

# Builds test executables

$(TESTS): $(AR_OBJECTS)
	$(CXX) $(CXXFLAGS) -c -o $@.o $@.cpp
	$(CXX) $(LDFLAGS) -o $@ $@.o $^ $(LDLIBS)
	@rm $@.o

test: CXXFLAGS  += $(shell pkg-config check --CXXFLAGS) -DTEST_BUILD
test: LDFLAGS += $(shell pkg-config check --libs-only-L)
test: LDLIBS  += $(shell pkg-config check --libs-only-l)
test: clean_objects $(TESTS)
	$(addsuffix ;,$(TESTS))
	rm $(TESTS)
	rm -f $(AR_OBJECTS)

# Checks for potentially unsafe functions

BADFUNCS = '[^_.>a-zA-Z0-9](str(n?cpy|n?cat|xfrm|n?dup|str|pbrk|tok|_)|stpn?cpy|a?sn?printf|byte_)'
check:
	@echo Files with potentially dangerous functions.
	@egrep $(BADFUNCS) $(SOURCES) || true

# Dependency file hacks
# Requires all dependency files, but doesn't error out if they
# aren't there

$(DEP_DIR)/%.d: ;
.PRECIOUS: $(DEP_DIR)/%.d
-include $(patsubst $(SRC_DIR)/%.cpp,$(OBJ_DIR)/%.d,$(SOURCES))
