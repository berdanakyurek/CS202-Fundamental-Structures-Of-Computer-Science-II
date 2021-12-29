
all: simulator_Q1 simulator_Q2

simulator_Q1: simulator_Q1.o maxHeap1.o
	g++ -g maxHeap1.o simulator_Q1.o -o simulator_Q1 -std=c++11

simulator_Q2: simulator_Q2.o maxHeap2.o
	g++ -g maxHeap2.o simulator_Q2.o -o simulator_Q2 -std=c++11

simulator_Q1.o: simulator.cpp
	g++ -DHEAP1 -g -c simulator.cpp -std=c++11 -o simulator_Q1.o

simulator_Q2.o: simulator.cpp
	g++ -DHEAP2 -g -c simulator.cpp -std=c++11 -o simulator_Q2.o

maxHeap1.o: maxHeap1.cpp
	g++ -g -c maxHeap1.cpp

maxHeap2.o: maxHeap2.cpp
	g++ -g -c maxHeap2.cpp

clean: 
	rm *.o simulator_Q1 simulator_Q2

