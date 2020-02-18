#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<unsigned> knapsack(vector<unsigned> size, vector<unsigned> value, unsigned capacity) {
    unsigned n = size.size();
    vector<unsigned> cost(capacity + 1);
    vector<unsigned> best(capacity + 1);
    // Adding an item at time
    for (unsigned item = 0; item < n; ++item)
        // Simulating bags with capacity starting at the size of the item i'm adding till the real bag capacity
        for (unsigned bag_size = size[item]; bag_size <= capacity; ++bag_size)
            // If the value of the bag would be better if this item was added, then change the data
            if (value[item] + cost[bag_size - size[item]] > cost[bag_size]) {
                cost[bag_size] = value[item] + cost[bag_size - size[item]];
                best[bag_size] = item;
            }
    vector<unsigned> result;
    for (unsigned j = capacity; j > 0; j -= size[best[j]])
        result.push_back(best[j]);
    return result;
}

int main() {
    vector<unsigned> s = {3, 4, 7, 8, 9};
    vector<unsigned> v = {4, 5, 10, 11, 13};
    vector<unsigned> r = knapsack(s, v, 17);
    sort(r.begin(), r.end());
    unsigned value = 0, size = 0;
    cout << "Itens: ";
    for (auto &x : r) {
        cout << x << ", ";
        value += v[x];
        size += s[x];
    }
    cout << "\nValue: " << value << "\nSize : " << size << endl;
    return 0;
}