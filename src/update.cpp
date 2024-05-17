#include "sudoku.h"

status sudoku::update(INDEX index, int value)
{
    if (index.first < 0 || index.second > 8 || index.second < 0 || index.second > 8 || value < 1 || value > 9)
    {
        std::cout << "ERROR : invalid input passed to update : " << index.first << "_" << index.second << "  value : " << value << std::endl;

        return status::error;
    }

    if (board[index.first][index.second] != 0)
    {
        std::cout << "ERROR : trying to change value : " << index.first << "_" << index.second << "  value : " << value << std::endl;
        return status::error;
    }

    if (!isAvailable(index, value))
    {
        return status::error;
    }

    board[index.first][index.second] = value;

    checkRow(index);
    checkColumn(index);
    checkMiniSudoku(index);
}
