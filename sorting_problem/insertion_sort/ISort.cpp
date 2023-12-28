#include <iostream>

class ISort
{
public:
    ISort(int *A_in, int n_in)
    {
        A = A_in;
        n = n_in;
    }

    void sort()
    {
        for (int i = 1; i < n; i++)
        {
            int key = A[i];
            int j = i - 1;
            while (j >= 0 && A[j] > key)
            {
                A[j + 1] = A[j];
                j--;
            }
            A[j + 1] = key;
        }
    }

private:
    int *A, n;
};

int main()
{
    int A[] = {10, 4, 2, 6, 9, 3};
    int n = 6;

    ISort array = ISort(A, n);
    array.sort();

    for (int i = 0; i < n; i++)
    {
        std::cout << A[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}