# Makefile for gtest examples

GOOGLE_TEST_LIB = /usr/local/lib/googletest/libgtest.a
GOOGLE_MOCK_LIB = /usr/local/lib/googletest/libgmock.a
GOOGLE_TEST_INCLUDE = /usr/local/lib/googletest/googletest/include
GOOGLE_MOCK_INCLUDE = /usr/local/lib/googletest/googlemock/include

G++ = g++
G++_FLAGS = -c -Wall -isystem $(GOOGLE_TEST_INCLUDE) -isystem $(GOOGLE_MOCK_INCLUDE)
LD_FLAGS = $(GOOGLE_TEST_LIB) $(GOOGLE_MOCK_LIB) -l pthread

OBJECTS = run_tests.o testTypeList.o testIfThenElse.o testVariantStorage.o testVariantChoice.o
TARGET = run_tests

all: $(TARGET)

test:
	./run_tests

$(TARGET): $(OBJECTS)
	g++ -o $(TARGET) $(OBJECTS) $(LD_FLAGS) -std=c++1z

%.o : %.cpp 
	$(G++) $(G++_FLAGS) $< -std=c++1z

clean: 
	rm -f $(TARGET) $(OBJECTS)
                    
.PHONY: all clean
