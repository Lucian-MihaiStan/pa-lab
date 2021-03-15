#include <vector>

class mergesort {
private:
	int n;
	std::vector<int> v;

public:
	explicit mergesort(int _n, std::vector<int> _v);
	void solve();
	void MergeSort(int left, int right);
	void Merge(int left, int right);
	std::vector<int> getV();
};