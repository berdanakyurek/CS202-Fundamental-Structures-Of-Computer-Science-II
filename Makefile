
hw2: main.cpp Heap.cpp Heap.h Node.cpp Node.h Process.cpp Process.h simulator.cpp simulator.h
	g++ -std=c++11 -g -o simulator simulator.cpp Node.cpp Heap.cpp main.cpp Process.cpp
clean:
	rm -rf simulator

