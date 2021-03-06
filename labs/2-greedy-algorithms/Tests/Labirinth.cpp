/*
 * labirinth.cpp
 */

#include "Labirinth.h"

#include <iostream>

using namespace std;


Labirinth::Labirinth(int values[10][10]) {
    for (int i = 0; i < 10; i++)
        for (int j = 0; j < 10; j++)
            labirinth[i][j] = values[i][j];
    initializeVisited();
}


void Labirinth::initializeVisited() {
    for (int i = 0; i < 10; i++)
        for (int j = 0; j < 10; j++)
            visited[i][j] = false;
}


void Labirinth::printLabirinth() {
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++)
            cout << labirinth[i][j] << " ";

        cout << endl;
    }
}

bool Labirinth::promising(int x, int y) {
    if (visited[x][y])
        return false;
    if (x < 0 || y < 0 || x >= 10 || y >= 10)
        return false;
    return labirinth[x][y] != 0;
}

bool Labirinth::findGoal(int x, int y) {
    if (labirinth[x][y] == 2)
        return true;
    if (promising(x, y)) {
        visited[x][y] = true;
        return findGoal(x - 1, y) || findGoal(x + 1, y) || findGoal(x, y - 1) || findGoal(x, y + 1);
    }
    return false;
}


