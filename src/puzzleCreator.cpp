#include "sudoku.h"

#include <algorithm>

sudoku generateSudoku(int64_t solSeed, int64_t puzzleSeed, int freeCells = 81)
{
    sudoku puzzle;
    std::mt19937 gen(solSeed); // Initialize the generator with the seed
    std::uniform_int_distribution<> dis(1, 9); // Define a distribution

    puzzle.solve(gen,dis);

    /*implement difficulty*/
    std::mt19937 g(puzzleSeed);
    std::uniform_int_distribution<> d(0,80);

    sudoku rollback = puzzle;
    for (int i = 0; i < freeCells; i++)
    {
        int k = d(g);
        INDEX index = {k / 9, k % 9};

        puzzle.remove(index);
        
        if (!puzzle.uniquePuzzle())
        {
            puzzle = rollback;
            break;
        }

        rollback.remove(index);
    }

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
        std::mt19937 g(puzzleSeed);

        temp.solve(g);

        if (!(temp == solution || solution == bits::emptyBoard))
        {
            return false;
        }
        solution = temp;
    }
    return true;
}
