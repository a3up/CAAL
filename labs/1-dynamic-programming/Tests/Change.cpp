/*
 * Change.cpp
 */

#include "Change.h"
#include <vector>

// minCoins(i, k) = min(1 + minCoins(i, k - coinValues[i]), minCoins(i - 1, k)), 0 se for impossível
// lastCoin(i, k) = i (primeiro argumento acima) ou lastCoin(i - 1, k) (segundo argumento), 0 se for impossível

string calcChange(int m, int numCoins, int *coinValues) {
    vector<int> coinCount(m + 1); // Menor número de moedas para um troco n
    vector<int> lastCoin(m + 1);  // Última moeda selecionada para o menor número de moedas do troco n
    // Using one coin at time
    for (int coin = 0; coin < numCoins; ++coin) {
        int coinValue = coinValues[coin];
        for (int price = coinValue; price <= m; ++price) {
            if (coinValue > price)
                continue;
            if (coinCount[price] == 0 || 1 + coinCount[price - coinValue] < coinCount[price]) {
                coinCount[price] = 1 + coinCount[price - coinValue];
                lastCoin[price] = coin;
            }
        }
    }
    string res = "";
    while (coinCount[m] > 0) {
        int toAdd = lastCoin[m];
        res += to_string(coinValues[toAdd]) + ";";
        m -= coinValues[toAdd];
    }
    return m ? "-" : res;
}


