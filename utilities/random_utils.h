#include <random>

void generateRandomInt (int * A, int n, int bound=100) {
    srand(time(0));

    for (int i = 0; i < n; i++) {
        A[i] = (rand() % bound);
    }
}