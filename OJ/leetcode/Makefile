CXX = g++
CPPFLAGS += -isystem $(GTEST_DIR)/include
CXXFLAGS += -g -Wall -Wextra -std=c++11

BUILD_DIR = build
EXE_DIR = bin
INCLUDE_DIR = include
LIB_DIR = lib
GTEST_DIR = $(LIB_DIR)/gtest

SOURCES:=$(wildcard test/*.cpp)
SRC:=$(notdir $(SOURCES))
TARGETS:=$(patsubst %.cpp, $(EXE_DIR)/%, $(SRC))
DEPENDS:=$(patsubst %.cpp, $(BUILD_DIR)/%.d, $(SRC))
BUILD_INCLUDE_DIR:=$(INCLUDE_DIR) src $(GTEST_DIR)/include 
BUILD_INCLUDE_FLAG:=$(foreach d,$(BUILD_INCLUDE_DIR),-I$(d))

DEP_INCLUDE_DIR:=$(INCLUDE_DIR) src 
DEP_INCLUDE_FLAG:=$(foreach d,$(DEP_INCLUDE_DIR),-I$(d))

# Build the gtest 
GTEST_HEADERS = $(GTEST_DIR)/include/gtest/*.h \
                $(GTEST_DIR)/include/gtest/internal/*.h
GTEST_SRCS_ = $(GTEST_DIR)/src/*.cc $(GTEST_DIR)/src/*.h $(GTEST_HEADERS)

all: $(TARGETS)


#post about dependency: http://scottmcpeak.com/autodepend/autodepend.html
-include $(DEPENDS)

$(BUILD_DIR)/%.d : test/%.cpp
	@set -e; rm -f $@; \
	$(CXX) $(BUILD_INCLUDE_FLAG) -MM $< > $@.tmp; \
    sed 's,\($*\)\.o[ :]*,$(EXE_DIR)\/\1 $@ : ,g' < $@.tmp > $@; \
    rm -f $@.tmp

clean:
	rm -rf ./$(BUILD_DIR)/* ./$(EXE_DIR)/*

$(BUILD_DIR)/gtest-all.o : $(GTEST_SRCS_)
	$(CXX) $(CPPFLAGS) -I$(GTEST_DIR) $(CXXFLAGS) -c \
            $(GTEST_DIR)/src/gtest-all.cc -o $@

$(BUILD_DIR)/gtest_main.o : $(GTEST_SRCS_)
	$(CXX) $(CPPFLAGS) -I$(GTEST_DIR) $(CXXFLAGS) -c \
            $(GTEST_DIR)/src/gtest_main.cc -o $@

$(BUILD_DIR)/gtest_main.a : $(BUILD_DIR)/gtest-all.o $(BUILD_DIR)/gtest_main.o
	$(AR) $(ARFLAGS) $@ $^

$(EXE_DIR)/% : test/%.cpp $(BUILD_DIR)/gtest_main.a
	$(CXX) $(CXXFLAGS) $(BUILD_INCLUDE_FLAG) -lpthread $<  $(BUILD_DIR)/gtest_main.a -o $@

