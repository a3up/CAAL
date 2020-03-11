#include <vector>
#include <iostream>

using namespace std;

vector<unsigned> select(unsigned m, vector<unsigned> values, vector<unsigned> stock) {
    vector<unsigned> result(values.size());
    for (unsigned i = values.size() - 1; m > 0 && i >= 0; i--) {
        if (stock[i] > 0 && values[i] <= m) {
            int coins_number = min(stock[i], m / values[i]);
            result[i] += coins_number;
            m -= coins_number * values[i];
        }
    }
    return result;
}

int main() {
    vector<unsigned> values = {1, 2, 5, 10};
    vector<unsigned> stock = {3, 4, 2, 1};
    vector<unsigned> result = select(9, values, stock);
    for (unsigned i = 0; i < result.size(); ++i)
        switch (result[i]) {
            case 0:
                break;
            case 1:
                cout << result[i] << " coin of " << values[i] << "\n";
                break;
            default:
                cout << result[i] << " coins of " << values[i] << "\n";
        }
    return 0;
}