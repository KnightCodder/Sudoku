#include "sudoku.h"

int main()
{
    int inputBoard[9][9] = {
        {5, 3, 0, 0, 7, 0, 0, 0, 0},
        {6, 0, 0, 1, 9, 5, 0, 0, 0},
        {0, 9, 8, 0, 0, 0, 0, 6, 0},
        {8, 0, 0, 0, 6, 0, 0, 0, 3},
        {4, 0, 0, 8, 0, 3, 0, 0, 1},
        {7, 0, 0, 0, 2, 0, 0, 0, 6},
        {0, 6, 0, 0, 0, 0, 2, 8, 0},
        {0, 0, 0, 4, 1, 9, 0, 0, 5},
        {0, 0, 0, 0, 8, 0, 0, 7, 9}
    };

    sudoku puzzle(inputBoard);
    std::cout << "Original Sudoku Board:" << std::endl;
    puzzle.print();

    if (puzzle.solve())
    {
        std::cout << "Solved Sudoku Board:" << std::endl;
        puzzle.print();
    }
    else
    {
        std::cout << "No solution exists for the given Sudoku puzzle." << std::endl;
    }

    return 0;
}