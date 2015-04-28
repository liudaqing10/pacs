CXX=g++
CC=$(CXX)

CXXFLAGS=-g -std=c++11 -Wall
LDFLAGS=-g

exee3: exehf.o exee3m.o 
	$(CC) $(LDFLAGS) -o exee3 exehf.o exee3m.o

exehf.o: exehf.cc
	$(CXX) -c $(CXXFLAGS) exehf.cc
exee3m.o: exee3m.cc
	$(CXX) -c $(CXXFLAGS) exee3m.cc

clean: exee3 exehf.o exee3m.o
	rm exee3 exehf.o exee3m.o


