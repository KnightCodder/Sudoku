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

int sudoku::difficulty()
{
    if (isSolved != 0)
        return -1;

    int numFilledCells = 0;
    int toughness = 0;

    // checking rows
    for (int row = 0; row < 9; row++)
    {
        int filled = 0;
        for (int col = 0; col < 9; col++)
        {
            if (board[row][col] != 0)
            {
                numFilledCells++;
                filled++;
            }
        }

        toughness += (8 - filled) * (8 - filled) * (8 - filled);
    }

    // checking columns
    for (int col = 0; col < 9; col++)
    {
        int filled = 0;
        for (int row = 0; row < 9; row++)
        {
            if (board[row][col] != 0)
            {
                filled++;
            }
        }

        toughness += (8 - filled) * (8 - filled) * (8 - filled);
    }

    // checking mini sudoku
    for (int mini_row = 0; mini_row < 3; mini_row++)
    {
        for (int mini_col = 0; mini_col < 3; mini_col++)
        {
            int filled = 0;
            for (int row = mini_row * 3; row < 3*(mini_row + 1); row++)
            {
                for (int col = mini_col * 3; col < 3*(mini_col + 1); col++)
                {
                    if (board[row][col] != 0)
                        filled++;
                }
            }

            toughness += (8 - filled) * (8 - filled) * (8 - filled);
        }
    }

    return toughness;
}

sudoku generatePuzzle(int64_t seed, int ratingStartPoint = 0, int ratingEndPoint = 9999)
{
    std::mt19937 gen(seed); // Initialize the generator with the seed
    std::uniform_int_distribution<> dis; // Define a distribution

    while (true)
    {
        sudoku puzzle = generateSudoku(dis(gen), dis(gen));

        int difficulty = puzzle.difficulty();

        if (difficulty >= ratingStartPoint && difficulty <= ratingEndPoint)
            return puzzle;
    }
}

