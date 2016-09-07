.PHONY: all clean valgrind gdb test check

# Additional config for linking with Dusk

CXXFLAGS += -I$(DUSK_DIR)/$(SRC_DIR) -I$(DUSK_DIR)/$(SRC_DIR)/thirdparty
LDFLAGS  += -L$(DUSK_DIR)/$(BUILD_DIR)
LDLIBS   += -ldusk

LIBCMD = export LD_LIBRARY_PATH=$(DUSK_DIR)/$(BUILD_DIR)

# Dynamically get the sources/objects/tests

SOURCES = $(shell find $(SRC_DIR) -type f -name '*.cpp')
HEADERS = $(shell find $(SRC_DIR) -type f -name '*.hpp')
OBJECTS = $(patsubst $(SRC_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(SOURCES))
TESTS   = $(patsubst %.cpp,%,$(wildcard $(TESTS_DIR)/*_test.cpp))

# Create directories to prevent "cannot create file" errors

$(shell mkdir -p $(BUILD_DIR) $(TESTS_DIR) $(SRC_DIR) $(OBJ_DIR) $(DEP_DIR))
$(shell mkdir -p $(patsubst $(SRC_DIR)%,$(DEP_DIR)%,$(dir $(SOURCES))))
$(shell mkdir -p $(patsubst $(SRC_DIR)%,$(OBJ_DIR)%,$(dir $(SOURCES))))

# Build the main target

all: $(TARGET_PATH)

$(OBJ_DIR)/%.o : $(SRC_DIR)/%.cpp
$(OBJ_DIR)/%.o : $(SRC_DIR)/%.cpp $(DEP_DIR)/%.d
	$(CXX) $(CXXFLAGS) -MM -MP -MT $@ -o $(DEP_DIR)/$*.d $<
	$(CXX) $(CXXFLAGS) -c -o $@ $<

$(TARGET_PATH): $(OBJECTS)
	$(CXX) $(LDFLAGS) -o $@ $^ $(LDLIBS)

# Clean dependencies, objects, or the main target

clean:
	rm -rf $(DEP_DIR) $(OBJ_DIR) $(TARGET_PATH)

clean_deps:
	rm -rf $(DEP_DIR)

clean_objects:
	rm -f $(OBJECTS)

clean_target:
	rm -f $(TARGET_PATH)

# Install to system

install: all
	install -d $(DESTDIR)/$(PREFIX)/bin/
	install $(TARGET_PATH) $(DESTDIR)/$(PREFIX)/bin/

# Format code

format:
	clang-format -style=file -i $(filter-out $(SRC_DIR)/thirdparty%,$(SOURCES)) \
		$(filter-out $(SRC_DIR)/thirdparty%,$(HEADERS))

# Run the program normally

run:
	$(LIBCMD); $(TARGET_PATH)

# Run the program through valgrind

valgrind:
	$(LIBCMD); valgrind $(TARGET_PATH)

# Run the program through gdb

gdb:
	$(LIBCMD); gdb --args $(TARGET_PATH)

# Builds test executables

$(TESTS): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -c -o $@.o $@.cpp
	$(CXX) $(LDFLAGS) -o $@ $@.o $^ $(LDLIBS)
	@rm $@.o

# Build and execute tests
# Adds CXXFLAGS,LDFLAGS,LDLIBS for libcheck
# Cleans objects before and after

test: CXXFLAGS  += $(shell pkg-config check --CXXFLAGS) -DTEST_BUILD
test: LDFLAGS += $(shell pkg-config check --libs-only-L)
test: LDLIBS  += $(shell pkg-config check --libs-only-l)
test: clean_objects $(TESTS)
	$(LIBCMD); $(addsuffix ;,$(TESTS))
	rm -f $(TESTS)
	rm -f $(OBJECTS)

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
-include $(patsubst $(SRC_DIR)/%.cpp,$(DEP_DIR)/%.d,$(SOURCES))
