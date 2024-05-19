#include "sudoku.h"

void sudoku::print()
{
    std::cout << "\n------------- ------------- -------------\n";
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
                std::cout << " |";
        }
        std::cout << "\n------------- ------------- -------------\n";

        // Add an extra horizontal line after every 3 rows
        if ((i + 1) % 3 == 0 && i < 8)
            std::cout << "------------- ------------- -------------\n";
    }
    std::cout << "is solved : " << isSolved << "\n"
              << std::endl;
}