#include <iostream>

using namespace std;

class BSort
{
public:
    BSort(int *A_in, int n_in)
    {
        A = A_in;
        n = n_in;
    }

    void sort()
    {
        for (int i = 0; i < n - 1; i++)
        {
            for (int j = n - 1; j > i; j--)
            {
                if (A[j] < A[j - 1])
                {
                    swap(j, j - 1);
                }
            }
        }
    }

private:
    int *A, n;

    void swap(int i, int j)
    {
        int tmp = A[i];
        A[i] = A[j];
        A[j] = tmp;
    }
};

int main()
{
    int A[] = {10, 4, 2, 6, 9, 3, 1};
    int n = 7;

    BSort array = BSort(A, n);
    array.sort();

    for (int i = 0; i < n; i++)
    {
        std::cout << A[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}