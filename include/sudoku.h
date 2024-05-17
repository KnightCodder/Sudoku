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

    void print()
    {
        std::cout << "\n---------------------------------------\n";
        for (int i = 0; i < 9; i++)
        {
            std::cout << "|";
            for (int j = 0; j < 9; j++)
            {
                if (board[i][j] != 0)
                    std::cout << " " << board[i][j] << " |";
                else
                    std::cout << " . |";

                // Add an extra vertical line after every 3 columns
                if ((j + 1) % 3 == 0 && j < 8)
                    std::cout << "|";
            }
            std::cout << "\n---------------------------------------\n";

            // Add an extra horizontal line after every 3 rows
            if ((i + 1) % 3 == 0 && i < 8)
                std::cout << "---------------------------------------\n";
        }
        std::cout << "is solved : " << isSolved << "\n"
                  << std::endl;
    }

    status checkRow(INDEX index)
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

    status checkColumn(INDEX index)
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

    status checkMiniSudoku(INDEX index)
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

    bool isAvailable(INDEX index, int value)
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

    status update(INDEX index, int value)
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
};

#endif