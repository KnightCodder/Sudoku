#include "sudoku.h"

status sudoku::checkRow(INDEX index)
{
    int check = 0;

    for (int i = 0; i < 9; i++)
    {
        check += board[index.first][i];
    }

    if (check == 45)
    {
        isSolved |= (1 << (index.first));

        return status::completed;
    }
    else
        return status::notCompleted;
}

status sudoku::checkColumn(INDEX index)
{
    int check = 0;

    for (int i = 0; i < 9; i++)
    {
        check += board[i][index.second];
    }

    if (check == 45)
    {
        isSolved |= (1 << (9 + index.second));
        return status::completed;
    }
    else
        return status::notCompleted;
}

status sudoku::checkMiniSudoku(INDEX index)
{
    int check = 0;

    INDEX si = {index.first - index.first % 3, index.second - index.second % 3};

    for (int i = si.first; i < si.first + 3; i++)
    {
        for (int j = si.second; j < si.second + 3; j++)
            check += board[i][j];
    }

    if (check == 45)
    {
        isSolved |= (1 << (18 + (si.first) + (index.second / 3)));
        return status::completed;
    }
    else
        return status::notCompleted;
}

bool sudoku::isAvailable(INDEX index, int value)
{
    for (int i = 0; i < 9; i++)
    {
        if (value == board[index.first][i] || value == board[i][index.second])
            return false;
    }

    INDEX si = {index.first - index.first % 3, index.second - index.second % 3};

    for (int i = si.first; i < si.first + 3; i++)
    {
        for (int j = si.second; j < si.second + 3; j++)
        {
            if (value == board[i][j])
            {
                return false;
            }
        }
    }

    return true;
}

