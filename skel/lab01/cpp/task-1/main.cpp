#include <bits/stdc++.h>
using namespace std;

class Task {
public:
    void solve() {
        read_input();
        print_output(get_result());
    }

private:
    int n, x;
    vector<int> v;

    void read_input() {
        ifstream fin("in");
        fin >> n;
        for (int i = 0, e; i < n; i++) {
            fin >> e;
            v.push_back(e);
        }
        fin >> x;
        fin.close();
    }

    int find_first() {
        // TODO: Cautati prima pozitie pe care se afla valoarea x
        // In cazul in care x nu apare in sir, returnati -1

    	int res = -1;
    	int left = 0, right = n - 1, mid;
    	while(1) {
    		mid = left + (right - left) / 2;
    		if(left >= right) return res;
    		if(v[mid] >= x) {
    			res = mid;
    			right = mid - 1;
    		} else {
    			left = mid + 1;
    		}
    	}

        return res;
    }

    int find_last() {
        // TODO: Cautati ultima pozitie pe care se afla valoarea x
        // In cazul in care x nu apare in sir, returnati -1
    	int res = -1;
    	int left = 0, right = n - 1, mid;
    	while(1) {
    		mid = left + (right - left) / 2;
    		if(left >= right) return res;
    		if(v[mid] <= x) {
    			res = mid;
    			left = mid + 1;
    		} else {
    			right = mid = 1;
    		}
    	}
        return res;
    }

    int get_result() {
        // TODO: Calculati numarul de aparitii ale lui x in vectorul v
        int left_occurrence =  find_first();
        int right_occurrence =  find_last();
        
        if(left_occurrence == - 1 || right_occurrence == -1) {
        	return 0;
        }

        cout << right_occurrence << " " << left_occurrence << endl;
        return right_occurrence - left_occurrence + 1;
    }

    void print_output(int result) {
        ofstream fout("out");
        fout << result << endl;
        fout.close();
    }
};

// [ATENTIE] NU modifica functia main!
int main() {
    // * se aloca un obiect Task pe heap
    // (se presupune ca e prea mare pentru a fi alocat pe stiva)
    // * se apeleaza metoda solve()
    // (citire, rezolvare, printare)
    // * se distruge obiectul si se elibereaza memoria
    auto* task = new (std::nothrow) Task{}; // hint: cppreference/nothrow
    if (!task) {
        std::cerr << "new failed: WTF are you doing? Throw your PC!\n";
        return -1;
    }
    task->solve();
    delete task;
    return 0;
}
