#ifndef SUDOKU_H
#define SUDOKU_H

#include "definations.h"
#include <random>
#include <vector>

class sudoku
{
    sudoku_board board = {};
public:
    int isSolved = bits::notsolved;
    std::array<std::array<bool, 9>, 9> lockedCells;

    sudoku(int inputBoard[9][9] = bits::emptyBoard)
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
        return board == other.board;
    }
    bool operator<(const sudoku &other) const
    {
        return board < other.board;
    }
    sudoku(const sudoku &other)
        : board(other.board), isSolved(other.isSolved) {}

    void print();
    status checkRow(INDEX index);
    status checkColumn(INDEX index);
    status checkMiniSudoku(INDEX index);
    bool isAvailable(INDEX index, int value);
    status update(INDEX index, int value);
    void remove(INDEX index);
    bool solve(std::mt19937& gen = *(new std::mt19937(0)), std::uniform_int_distribution<>& dis = *(new std::uniform_int_distribution<>(1, 9)));
    bool uniquePuzzle(int tries = 10, int seed = 0);
    std::string toString()
    {
        std::string str = "";

        for (auto row : board)
        {
            for (auto cell : row)
            {
                str += std::to_string(cell) + " ";
            }
        }

        return str;
    }
    void lockCells()
    {
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                if (board[i][j] == 0)
                    lockedCells[i][j] = false;
                else
                    lockedCells[i][j] = true;   
            }
        }
    }
    int difficulty();
};

sudoku generateSudoku(int64_t solSeed, int64_t puzzleSeed, int freeCells);

#endif
