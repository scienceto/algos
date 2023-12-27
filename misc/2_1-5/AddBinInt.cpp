#include <iostream>
#include <math.h>

class AddBinInt
{
public:
    AddBinInt(int *A_in, int *B_in, int *C_in, int n_in)
    {
        A = A_in;
        B = B_in;
        C = C_in;
        n = n_in;
    }

    void addBin()
    {
        int carry = 0;
        for (int i = n - 1; i >= 0; i--)
        {
            C[i + 1] = (A[i] + B[i] + carry) % 2;
            std::cout << carry << " " << A[i] << " " << B[i] << " = " << C[i + 1] << std::endl;
            if ((A[i] + B[i] + carry) > 1)
            {
                carry = 1;
            }
            else
            {
                carry = 0;
            }
        }
        C[0] = carry;
        std::cout << carry << "    " << " = " << C[0] << std::endl;
    }

private:
    int n, *A, *B, *C;
};

int main()
{
    int n = 8;
    int A[] = {1, 0, 1, 0, 0, 1, 1, 1};
    int B[] = {1, 1, 1, 0, 1, 0, 1, 0};
    int C[n + 1];

    AddBinInt addBinInt = AddBinInt(A, B, C, n);
    addBinInt.addBin();

    int A_10 = 0;
    int B_10 = 0;
    int C_10 = 0;

    for (int i = 0; i < n; i++) {
        int multiplier = (int) pow(2, n-i-1);
        A_10 += A[i] * multiplier;
        B_10 += B[i] * multiplier;
        C_10 += C[i] * (int) pow(2, n-i);
        // std::cout << A[n-i-1] << " " << B[n-1-i] << " = " << C[n-i] << std::endl;
    }
    C_10 += C[n] * (int) pow(2, 0);

    std::cout << A_10 << " + " << B_10 << " = " << C_10 << std::endl;
}