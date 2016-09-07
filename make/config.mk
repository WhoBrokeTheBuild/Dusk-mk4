
# Installation directory

PREFIX ?= /usr/local

# Directory constants

BUILD_DIR = build
TESTS_DIR = tests
SRC_DIR = src
OBJ_DIR = obj
DEP_DIR = .dep

# Additional build configuration

CXXFLAGS += -g -Wall -std=c++11 -I$(SRC_DIR) -I$(SRC_DIR)/thirdparty
LDFLAGS  +=
LDLIBS   +=

TARGET_PATH = $(BUILD_DIR)/$(TARGET)

# Library settings

CXXFLAGS += $(shell pkg-config sfml-graphics sfml-window sfml-audio sfml-network sfml-system --cflags)
LDFLAGS  += $(shell pkg-config sfml-graphics sfml-window sfml-audio sfml-network sfml-system --libs-only-L)
LDLIBS   += $(shell pkg-config sfml-graphics sfml-window sfml-audio sfml-network sfml-system --libs-only-l)

CXXFLAGS += $(shell pkg-config --silence-errors --cflags      lua) \
						$(shell pkg-config --silence-errors --cflags      lua5.2)
LDFLAGS  += $(shell pkg-config --silence-errors --libs-only-L lua) \
 						$(shell pkg-config --silence-errors --libs-only-L lua5.2)
LDLIBS   += $(shell pkg-config --silence-errors --libs-only-l lua) \
						$(shell pkg-config --silence-errors --libs-only-l lua5.2)

CXXFLAGS += -DASIO_STANDALONE
