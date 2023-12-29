#include <iostream>
#include "../../searching_problem/binary_search/BSearchRecursion.cpp"
#include "../../sorting_problem/merge_sort/MSort.cpp"

using namespace std;

class SumEqual
{
public:
    SumEqual(int *A_in, int n_in)
    {
        A = A_in;
        n = n_in;
    }

    bool sumIndices(int v)
    {
        MSort mSort = MSort(A, n);
        mSort.sort();

        BSearchRecusion bSearch = BSearchRecusion(A, n);

        if ((2 * A[n - 1]) < v)
        {
            cout << "No results..." << endl;
            return false;
        }

        for (int i = 0; i < n - 1; i++)
        {
            int add_v = v - A[i];
            int j = bSearch.search(add_v, i + 1);
            if (j != -1)
            {
                cout << A[i] << ", " << A[j] << " = " << v << endl;
                return true;
            }
        }

        cout << "No results..." << endl;
        return false;
    }

private:
    int *A, n;
};

int main()
{
    int n = 9;

    int A[] = {4, 5, 7, 3, 12, 55, 9, 6, 11};

    SumEqual sumEqual = SumEqual(A, n);

    sumEqual.sumIndices(10);
    sumEqual.sumIndices(7);
    sumEqual.sumIndices(5);
}