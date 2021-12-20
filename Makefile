
# * Title: Sorting and Algorithm Efficiency
# * Author: Berdan Akyurek
# * ID: 21600904
# * Section: 2
# * Assignment: 1
# * Description: makefile that compile all files
# */

hw1: main.cpp sorting.cpp sorting.h 
	g++ -o hw1 main.cpp sorting.cpp
clean:
	rm -rf hw1
