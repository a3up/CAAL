/*
 * Sum.cpp
 */

#include "Sum.h"
#include <chrono>
#include <vector>
#include <algorithm>
#include <sstream>

using namespace std;

string calcSum(int *sequence, int size) {
    vector<int> partial(size);
    stringstream res;
    for (int i = 0; i < size; ++i)
        partial[i] = sequence[i];
    auto m = min_element(partial.begin(), partial.end());
    res << *m << ',' << m - partial.begin() << ';';
    for (int n = 1; n < size; ++n) {
        for (int i = 0; i < size; ++i)
            partial[i] += sequence[i + n];
        partial.pop_back();
        m = min_element(partial.begin(), partial.end());
        res << *m << ',' << m - partial.begin() << ';';
    }
    return res.str();
}
