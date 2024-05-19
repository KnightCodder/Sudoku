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

// Function to solve the Sudoku puzzle using backtracking
bool sudoku::solve()
{
    int row, col;
    if (!findEmptyCell(board, row, col))
        return true;

    sudoku rollback = *this;
    for (int num = 1; num <= 9; num++)
    {
        INDEX index = {row, col};
        if (isAvailable(index, num))
        {
            update(index, num);
            if (solve())
                return true;
            *this = rollback;
        }
    }
    return false;
}
