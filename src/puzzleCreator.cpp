#include "sudoku.h"

#include <algorithm>

sudoku generateSudoku(int64_t seed, int freeCells)
{
    sudoku puzzle;
    std::mt19937 gen(seed); // Initialize the generator with the seed
    std::uniform_int_distribution<> dis(1, 9); // Define a distribution

    puzzle.solve(gen,dis);

    /*implement difficulty*/

    return puzzle;
}

bool sudoku::uniquePuzzle(int tries, int seed)
{
    std::mt19937 gen(seed);
    std::uniform_int_distribution<> dis(0,100);

    sudoku solution;
    for (int i = 0; i < tries; i++)
    {
        sudoku temp = *this;
        int puzzleSeed = dis(gen);
        temp.solve(std::mt19937(puzzleSeed));

        if (!(temp == solution || solution == bits::emptyBoard))
        {
            return false;
        }
        solution = temp;
    }
    return true;
}
