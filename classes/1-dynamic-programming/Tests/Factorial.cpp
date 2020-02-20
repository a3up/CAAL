/*
 * Factorial.cpp
 */

#include "Factorial.h"

int factorialRecurs(int n) {
    if (n <= 1)
        return 1;
    return n * factorialRecurs(n - 1);
}

int factorialDinam(int n) {
    int res = 1;
    for (int i = 2; i <= n; ++i)
        res *= i;
    return res;
}
