#include <iostream>
#include "../../utilities/random_utils.h"

using namespace std;

class ISortRecursion {
public:
    ISortRecursion (int * A_in, int n_in) {
        A = A_in;
        n = n_in;
    }

    void sort () {
        insertionSort(n - 1);
    }

private:
    int *A, n;

    void insertionSort (int p) {
        if (p < 2) {
            return;
        }
        insertionSort(p - 1);
        int j = p - 1;
        int key = A[p];
        while (j >= 0 && A[j] > key) {
            A[j + 1] = A[j];
            j--;
        }
        A[j + 1] = key;
    }
};

int main () {
    int n = 100;
    int A[n];

    generateRandomInt(A, n);

    ISortRecursion array = ISortRecursion(A, n);
    array.sort();

    for (int i = 0; i < n; i++)
    {
        cout << i + 1 << ": " << A[i] << endl;
    }
    cout << endl;

    return 0;
}