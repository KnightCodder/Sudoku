#include "sudoku.h"

INDEX nextIndex(INDEX index)
{
    if (index.second == 8)
        return {index.first + 1, 0};
    else
        return {index.first, index.second + 1};
}

bool findEmptyCell(sudoku_board &board, int &row, int &col)
{
    for (row = 0; row < 9; row++)
    {
        for (col = 0; col < 9; col++)
        {
            if (board[row][col] == 0)
                return true;
        }
    }
    return false;
}

// Function to solve the Sudoku puzzle using backtracking in a random way so that we could also check if a position has multiple solutions or not
bool sudoku::solve(std::mt19937& gen, std::uniform_int_distribution<>& dis)
{
    int row, col;
    if (!findEmptyCell(board, row, col))
        return true;

    int allVariableDone = 0;
    sudoku rollback = *this;
    while (allVariableDone != 511)
    {
        int k = dis(gen);
        int temp = allVariableDone | (1 << (k - 1));
        if (temp == allVariableDone)
            continue;
        allVariableDone = temp;

        INDEX index = {row, col};
        if (isAvailable(index, k))
        {
            update(index, k);
            if (solve(gen, dis))
                return true;
            *this = rollback;
        }
    }
    return false;
}
