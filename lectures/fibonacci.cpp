#include <iostream>

using namespace std;

unsigned fibonacci(unsigned n) {
    unsigned c[] = {0, 1};
    unsigned aux;
    for (unsigned i = 0; i < n; ++i) {
        aux = c[0];
        c[0] = c[1];
        c[1] += aux;
    }
    return c[0];
}

int main() {
    cout << fibonacci(5) << endl;
    return 0;
}