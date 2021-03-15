#include "mergesort.hpp"
#include <iostream>

mergesort::mergesort(int _n, std::vector<int> _v) {
	this->n = _n;
	this->v = _v;
} 

void mergesort::solve() {
	int left = 0, right = n;
	MergeSort(left, right);
}

void mergesort::MergeSort(int left, int right) {
	if(left >= right) return;
	int mid = left + (right - left) / 2;
	MergeSort(left, mid);
	MergeSort(mid + 1, right);
	Merge(left, right);
}

void mergesort::Merge(int left, int right) {
	int mid = left + (right - left) / 2;
	std::vector<int> temp;

	int i = left;
	int j = mid + 1;

	while(i <= mid && j <= right) {
		if(v[i] <= v[j]) temp.push_back(v[i++]);
		else temp.push_back(v[j++]);
	}

	while(i <= mid) temp.push_back(v[i++]);
	while(j <= right) temp.push_back(v[j++]);


	for(int k = left; k <= right; k++) v[k] = temp[k - left];
}

std::vector<int> mergesort::getV() {
	return this->v;
}