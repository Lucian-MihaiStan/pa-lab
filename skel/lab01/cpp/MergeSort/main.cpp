#include <iostream>
#include <fstream>
#include <vector>
#include "mergesort.hpp"


int main() {
	std::ifstream file;
	file.open("input.txt");

	int noElements, x = 0;
	std::vector<int> v;


	file >> noElements;
	for(int i = 0; i < noElements; i++) {
		file >> x;
		v.push_back(x);
	}
	file.close();

	mergesort* task = new mergesort(noElements, v);

	task->solve();	

	std::vector<int> sortedArray = task->getV();

	for(long unsigned int i = 0; i < sortedArray.size(); i++) 
		std::cout<<sortedArray[i]<<" ";

	std::cout<<std::endl;

	delete task;

}