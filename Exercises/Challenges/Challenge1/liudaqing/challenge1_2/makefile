CXX=g++
CC=$(CXX)

CXXFLAGS=-g -std=c++11 -Wall
LDFLAGS=-g

exee2: exehf.o exee2m.o 
	$(CC) $(LDFLAGS) -o exee2 exehf.o exee2m.o

exehf.o: exehf.cc
	$(CXX) -c $(CXXFLAGS) exehf.cc
exee1m.o: exee2m.cc
	$(CXX) -c $(CXXFLAGS) exee2m.cc

clean: exee2 exehf.o exee2m.o
	rm exee2 exehf.o exee2m.o


