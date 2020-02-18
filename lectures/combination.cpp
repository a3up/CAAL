#include <iostream>
#include <vector>

using namespace std;

unsigned combination(unsigned n, unsigned k) {
    vector<unsigned> c(n - k + 1, 1);
    for (unsigned j = 1; j <= k; ++j)
        for (unsigned i = 1; i <= n - k; ++i)
            c[i] += c[i - 1];
    return c[n - k];
}

int main() {
    cout << combination(5, 2) << endl;
    return 0;
}