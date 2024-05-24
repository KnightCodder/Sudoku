#ifndef DEFINATIONS_H
#define DEFINATIONS_H

#include <array>
#include <iostream>
#include <random>
#include <string>

#define sudoku_board std::array<std::array<int, 9>, 9>
#define INDEX std::pair<int, int>

enum class status
{
    error,
    completed,
    notCompleted,
    needAnotherValue
};

enum class calculationCalls
{
    filled,
    error,
    finished,
    stillSolving,
    needAnotherValue,
    errorInSudoku
};

namespace bits
{
    const int solved = 134217727;
    const int notsolved = 0;

    extern int emptyBoard[9][9];
}

#endif