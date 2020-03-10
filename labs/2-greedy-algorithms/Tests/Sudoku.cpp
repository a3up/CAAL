/*
 * Sudoku.cpp
 *
 */

#include "Sudoku.h"

/** Inicia um Sudoku vazio.
 */
Sudoku::Sudoku() {
    this->initialize();
}

/**
 * Inicia um Sudoku com um conteúdo inicial.
 * Lança excepção IllegalArgumentException se os valores
 * estiverem fora da gama de 1 a 9 ou se existirem números repetidos
 * por linha, coluna ou bloc 3x3.
 *
 * @param nums matriz com os valores iniciais (0 significa por preencher)
 */
Sudoku::Sudoku(int nums[9][9]) {
    this->initialize();

    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if (nums[i][j] != 0) {
                int n = nums[i][j];
                numbers[i][j] = n;
                lineHasNumber[i][n] = true;
                columnHasNumber[j][n] = true;
                block3x3HasNumber[i / 3][j / 3][n] = true;
                countFilled++;
            }
        }
    }
}

void Sudoku::initialize() {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            for (int n = 0; n < 10; n++) {
                numbers[i][j] = 0;
                lineHasNumber[i][n] = false;
                columnHasNumber[j][n] = false;
                block3x3HasNumber[i / 3][j / 3][n] = false;
            }
        }
    }

    this->countFilled = 0;
}

/**
 * Obtem o conteúdo actual (só para leitura!).
 */
int **Sudoku::getNumbers() {
    int **ret = new int *[9];

    for (int i = 0; i < 9; i++) {
        ret[i] = new int[9];

        for (int a = 0; a < 9; a++)
            ret[i][a] = numbers[i][a];
    }

    return ret;
}

/**
 * Verifica se o Sudoku já está completamente resolvido
 */
bool Sudoku::isComplete() {
    return countFilled == 9 * 9;
}

vector<int> Sudoku::noPossible(int x, int y) {
    vector<bool> n(9, false);
    vector<int> res;
    for (int i = 0; i < 9; i++) {
        n[i] = lineHasNumber[x][i + 1] || columnHasNumber[y][i + 1] || block3x3HasNumber[x / 3][y / 3][i + 1];
        if (!n[i])
            res.push_back(i + 1);
    }
    return res;
}

void Sudoku::addNumber(int x, int y, int number) {
    numbers[x][y] = number;
    lineHasNumber[x][number] = true;
    columnHasNumber[y][number] = true;
    block3x3HasNumber[x / 3][y / 3][number] = true;
    countFilled++;
}

void Sudoku::removeNumber(int x, int y) {
    int number = numbers[x][y];
    numbers[x][y] = 0;
    lineHasNumber[x][number] = false;
    columnHasNumber[y][number] = false;
    block3x3HasNumber[x / 3][y / 3][number] = false;
    countFilled--;
}

/**
 * Resolve o Sudoku.
 * Retorna indicação de sucesso ou insucesso (sudoku impossível).
 */
bool Sudoku::solve() {
    if (isComplete())
        return true;
    int min_pos[2];
    int value = 10;
    vector<int> n;
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            if (numbers[i][j] != 0)
                continue;
            n = noPossible(i, j);
            if (n.empty())
                return false;
            if (n.size() < value) {
                value = n.size();
                min_pos[0] = i;
                min_pos[1] = j;
                if (value == 1) {
                    break;
                }
            }

        }
    }
    n = noPossible(min_pos[0], min_pos[1]);
    for (auto &poss : n) {
        addNumber(min_pos[0], min_pos[1], poss);
        if (solve())
            return true;
        removeNumber(min_pos[0], min_pos[1]);
    }
    return false;
}

/**
 * Imprime o Sudoku.
 */
void Sudoku::print() {
    for (int i = 0; i < 9; i++) {
        for (int a = 0; a < 9; a++)
            cout << this->numbers[i][a] << " ";
        cout << endl;
    }
}
