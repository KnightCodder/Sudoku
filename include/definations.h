#ifndef DEFINATIONS_H
#define DEFINATIONS_H

#include <array>
#include <iostream>

#define sudoku_board std::array<std::array<int, 9>, 9>
#define INDEX std::pair<int, int>

enum class status
{
    error,
    completed,
    notCompleted
};

namespace bits
{
    const int solved = 134217727;
    const int notsolved = 0;

}

#endif