/*
 * Partioning.cpp
 */

#include "Partitioning.h"

#include <vector>
#include <iostream>
#include <numeric>

using namespace std;

int s_recursive(int n, int k) {
    if (k == 1 || k == n)
        return 1;
    return s_recursive(n - 1, k - 1) + k * s_recursive(n - 1, k);
}

int s_dynamic(int n, int k) {
    vector<int> partial(k + 1, 1);
    for (int i = 0; i < n; ++i)
        for (int j = min(i, k); j >= 0; --j)
            partial[j] = partial[j] * j + partial[j - 1];
    return partial[k];
}


int b_recursive(int n) {
    int res = 0;
    for(int k = 1; k <= n; ++k)
        res += s_recursive(n, k);
    return res;
}

int b_dynamic(int n) {
    vector<int> partial(n + 1, 1);
    for (int i = 0; i < n; ++i)
        for (int j = i; j >= 0; --j)
            partial[j] = partial[j] * j + partial[j - 1];
    return accumulate(partial.begin(), partial.end(), 0);
}


