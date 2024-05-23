#include "sudoku.h"

sudoku generateSudoku(int64_t solSeed, int64_t puzzleSeed, int freeCells);

int main()
{
    // int inputBoard[9][9] = {
    //     {5, 3, 0, 0, 7, 0, 0, 0, 0},
    //     {6, 0, 0, 1, 9, 5, 0, 0, 0},
    //     {0, 9, 8, 0, 0, 0, 0, 6, 0},
    //     {8, 0, 0, 0, 6, 0, 0, 0, 3},
    //     {4, 0, 0, 8, 0, 3, 0, 0, 1},
    //     {7, 0, 0, 0, 2, 0, 0, 0, 6},
    //     {0, 6, 0, 0, 0, 0, 2, 8, 0},
    //     {0, 0, 0, 4, 1, 9, 0, 0, 5},
    //     {0, 0, 0, 0, 8, 0, 0, 7, 9}
    // };

    // sudoku puzzle;
    // std::cout << "Original Sudoku Board:" << std::endl;
    // puzzle.print();

    // int64_t seed = 694; // Example seed value
    // std::mt19937 gen(seed); // Initialize the generator with the seed

    // std::uniform_int_distribution<> dis(1, 9); // Define a distribution


    // if (puzzle.solve(gen,dis))
    // {
    //     std::cout << "Solved Sudoku Board:" << std::endl;
    //     puzzle.print();
    // }
    // else
    // {
    //     std::cout << "No solution exists for the given Sudoku puzzle." << std::endl;
    // }

    // if (puzzle.uniquePuzzle())
    // {
    //     std::cout << "unique" << std::endl;
    // }
    // else
    //     std::cout << "not unique" << std::endl;

    sudoku puzzle = generateSudoku(69465,1954,81);
    
    puzzle.print();

    return 0;
}