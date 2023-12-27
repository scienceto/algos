#include <iostream>

using namespace std;

class LSearch
{
public:
    LSearch(int *A_in, int n_in)
    {
        A = A_in;
        n = n_in;
    }

    int search(int v)
    {
        int i = 0;
        while (i < n)
        {
            if (A[i] == v) {
                break;
            }
            i++;
        }

        if (i < n) {
            return i;
        }
        // returning -1 if value not present in the array (i.e. i > n one of the termination conditions)
        return -1;
    }

private:
    int n, *A;
};

int main () {
    int n = 5;

    int A[] = {2, 4, 1, 7, 3};

    LSearch lSearch = LSearch(A, n);

    cout << lSearch.search(2) << endl;
    cout << lSearch.search(6) << endl;
}