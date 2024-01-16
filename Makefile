CXX = g++
CXXFLAGS = -std=c++17 -g -Wall -O0

PROG ?= main
OBJS = Character.o Barbarian.o Mage.o Scoundrel.o main.o

all: $(PROG)

.cpp.o:
	$(CXX) $(CXXFLAGS) -c -o $@ $<

$(PROG): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $(OBJS)

clean:
	rm -rf $(EXEC) *.o *.out main 

rebuild: clean all