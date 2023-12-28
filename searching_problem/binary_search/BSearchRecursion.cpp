#include <iostream>

using namespace std;

class BSearchRecusion {
public:
    BSearchRecusion (int *A_in, int n_in) {
        A = A_in;
        n = n_in;
    }
    
    int search (int v) {
        return binarySearch(v, 0, n-1);
    }

private:
    int *A, n;

    int binarySearch (int v, int p, int q) {
        if (A[p] == v) {
            return p;
        }
        if (A[q] == v) {
            return q;
        }
        if ((q - p) < 2) {
            return -1;
        }
        int m = (p + q) / 2;
        int next_p = 0;
        int next_q = 0;
        if (A[m] >= v) {
            next_p = p;
            next_q = m;
        }
        if (A[m] < v) {
            next_p = m;
            next_q = q;
        }
        return binarySearch (v, next_p, next_q);
    }
};

int main () {
    int n = 9;

    int A[] = {2, 4, 1, 7, 3, 12, 55, 9, 6};

    BSearchRecusion bSearchRecursion = BSearchRecusion(A, n);

    cout << bSearchRecursion.search(55) << endl;
    cout << bSearchRecursion.search(22) << endl;
}