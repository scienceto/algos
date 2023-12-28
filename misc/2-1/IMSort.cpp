#include <iostream>
#include "../../utilities/random_utils.h"
#define SEGMENT 5

using namespace std;

class IMSort {
public:
    IMSort (int *A_in, int n_in) {
        A = A_in;
        n = n_in;
    }

    void sort () {
        mergeSort(0, n-1);
    }

private:
    int *A, n;

    void merge(int p, int q, int r) {
        int nl = q - p + 1;
        int nr = r - q;

        int L[nl], R[nr];

        for (int i = 0; i < nl; i++) {
            L[i] = A[p + i];
        }
        for (int i = 0; i < nr; i++) {
            R[i] = A[q + 1 + i];
        }

        int i = 0;
        int j = 0;
        int k = p;

        while (i < nl && j < nr) {
            if (L[i] < R[j]) {
                A[k] = L[i];
                i++;
            }
            else {
                A[k] = R[j];
                j++;
            }
            k++;
        }

        while (i < nl) {
            A[k] = L[i];
            i++;
            k++;
        }
        while (j < nr) {
            A[k] = R[j];
            j++;
            k++;
        }
    }

    void insertionSort (int p, int q) {
        for (int i = p + 1; i <= q; i++) {
            int key = A[i];
            int j = i - 1;
            while (j >= p && A[j] > key) {
                A[j + 1] = A[j];
                j--;
            }
            A[j + 1] = key;
        }
    }

    void mergeSort (int p, int r) {
        if ((r - p) <= SEGMENT) {
            insertionSort(p, r);
            return;
        }

        int q = (int) ((p + r) / 2);

        mergeSort(p, q);
        mergeSort(q+1, r);

        merge(p, q, r);
    }
};

int main()
{
    int n = 100;
    int A[n];

    generateRandomInt(A, n);

    IMSort array = IMSort(A, n);
    array.sort();

    for (int i = 0; i < n; i++)
    {
        std::cout << i + 1 << ": " << A[i] << endl;
    }
    std::cout << std::endl;

    return 0;
}