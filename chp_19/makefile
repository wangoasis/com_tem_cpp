CXX=g++
CXXFLAGS=-std=c++1z

IDIR=header
ODIR=obj
TDIR=test

DEPS=$(shell ls $(IDIR)/*.hpp)

_CPPS=$(shell ls *.cpp)
_OBJS=$(patsubst %.cpp, %.o, $(_CPPS))
OBJS=$(patsubst %, $(ODIR)/%, $(_OBJS))

_TESTS=$(patsubst %.cpp, %, $(_CPPS))
TESTS=$(patsubst %, $(TDIR)/%, $(_TESTS))

.PRECIOUS: $(OBJS)

test: $(TESTS)

$(ODIR)/%.o: %.cpp  $(DEPS)
	$(CXX) -c -Wall -o $@ $< $(CXXFLAGS)

$(TDIR)/%: $(ODIR)/%.o 
	$(CXX) -o $@ $^ $(CXXFLAGS)

check:
	$(TESTS)

clean:
	rm $(ODIR)/* $(TDIR)/*
