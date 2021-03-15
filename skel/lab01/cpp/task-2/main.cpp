#include <bits/stdc++.h>
using namespace std;

class Task {
public:
    void solve() {
        read_input();
        print_output(get_result());
    }

private:
    double n;

    void read_input() {
        ifstream fin("in");
        fin >> n;
        fin.close();
    }

    double get_result() {
        // TODO: Calculati sqrt(n) cu o precizie de 0.001
        // Precizie de 10^-x = |rezultatul vostru - rezultatul corect| <= 10^-x
        double left, right, middle;        
        if(n > 1) {
            left = 1;
            right = n;
        } 
        else if(n == 1) return 1;
        else {
            left = n;
            right = 1;
        } 

        double power2, precision;

        while(left <= right) {
            middle = left + (right - left) / 2;
            cout << left << " " << middle << " " << right << " " ;
            power2 = middle * middle;
            precision = fabs(power2 - n);
            cout << precision << endl;
            if(precision < 0.001) return middle;
            else if(n <= power2) right = middle - 0.0001;
            else if(n > power2) left = middle + 0.0001;
        }

        return middle;
    }

    void print_output(double result) {
        ofstream fout("out");
        fout << setprecision(4) << fixed << result << endl;
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
