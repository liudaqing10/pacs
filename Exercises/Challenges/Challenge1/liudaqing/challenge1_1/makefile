CXX=g++
CC=$(CXX)

CXXFLAGS=-g -std=c++11 -Wall
LDFLAGS=-g

exee1: exehf.o exee1m.o 
	$(CC) $(LDFLAGS) -o exee1 exehf.o exee1m.o

exehf.o: exehf.cc
	$(CXX) -c $(CXXFLAGS) exehf.cc
exee1m.o: exee1m.cc
	$(CXX) -c $(CXXFLAGS) exee1m.cc

clean: exee1 exehf.o exee1m.o
	rm exee1 exehf.o exee1m.o


