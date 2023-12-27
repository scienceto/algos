#include <iostream>

using namespace std;

class SSort {
public:
    SSort (int * A_in, int n_in) {
        A = A_in;
        n = n_in;
    }

    void sort () {
        for (int i = 0; i < n-1; i++) {
            for (int j = i + 1; j < n; j++) {
                if (A[i] > A[j]) {
                    int tmp_value = A[i];
                    A[i] = A[j];
                    A[j] = tmp_value;
                }
            }
        }
    }

private:
    int *A, n;
};

int main () {
    int n = 6;

    int A[] = {2, 5, 1, 3, 7, 2};

    SSort sSort = SSort(A, n);

    sSort.sort();

    for (int i = 0; i < n; i++) {
        cout << A[i] << " ";
    }
    cout << endl;
}