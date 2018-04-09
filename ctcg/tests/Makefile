# Makefile for gtest examples

GOOGLE_TEST_LIB = /usr/local/lib/googletest/libgtest.a
GOOGLE_TEST_INCLUDE = /usr/local/lib/googletest/googletest/include

G++ = g++
G++_FLAGS = -c -Wall -isystem $(GOOGLE_TEST_INCLUDE)
LD_FLAGS = $(GOOGLE_TEST_LIB) -l pthread

OBJECTS = run_tests.o testTypeList.o testIfThenElse.o
TARGET = run_tests

all: $(TARGET)

$(TARGET): $(OBJECTS)
	g++ -o $(TARGET) $(OBJECTS) $(LD_FLAGS) -std=c++1z

%.o : %.cpp 
	$(G++) $(G++_FLAGS) $< -std=c++1z

clean: 
	rm -f $(TARGET) $(OBJECTS)
                    
.PHONY: all clean
