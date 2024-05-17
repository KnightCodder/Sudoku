#include "sudoku.h"

void sudoku::solve()
{
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            if (isSolved == bits::solved)
                return;

            if (board[i][j] != 0)
                continue;

            bool isError = true;

            for (int v = 1; v <= 9; v++)
            {
                status s = update({i,j},v);

                if (s != status::error)
                    isError = false;
            }

            if (!isError)
            {
                std::cout << "no solution" << std::endl;
                return;
            }
        }
    }
}