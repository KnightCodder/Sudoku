#ifndef SUDOKU_H
#define SUDOKU_H

#include "definations.h"

class sudoku
{
    sudoku_board board = {};
    int isSolved = bits::notsolved;

public:
    sudoku(int inputBoard[9][9] = {})
    {
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                if (inputBoard[i][j] != 0)
                {
                    update({i, j}, inputBoard[i][j]);
                }
            }
        }
    }

    bool operator==(const sudoku &other) const
    {
        board == other.board;
    }
    bool operator<(const sudoku &other) const
    {
        board < other.board;
    }
    sudoku(sudoku &other)
    {
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                other.board[i][j] = board[i][j];
            }
        }

        other.isSolved = isSolved;
    }

    void print();
    status checkRow(INDEX index);
    status checkColumn(INDEX index);
    status checkMiniSudoku(INDEX index);
    bool isAvailable(INDEX index, int value);
    status update(INDEX index, int value);
    void solve();
};

#endif