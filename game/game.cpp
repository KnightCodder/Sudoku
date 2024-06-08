#include "sudoku.h"

sudoku generateSudoku(int64_t solSeed, int64_t puzzleSeed, int freeCells);

int main()
{
    int64_t solSeed, puzzleSeed;

    std::cout << "enter solution and puzzle seed : ";

    std::cin >> solSeed >> puzzleSeed;

    sudoku puzzle = generateSudoku(solSeed,puzzleSeed,81);
    puzzle.lockCells();
    int difficulty = puzzle.difficulty();

    sudoku solution;
    std::mt19937 gen(solSeed);
    solution.solve(gen);

    while (puzzle.isSolved != bits::solved)
    {
        puzzle.print();

        INDEX index;
        std::string operation;
        int value;

        std::cout << "input (row(0-8), column(0-8), operation(add, remove, quit), value(enter any number if you want to remove)) : ";
        std::cin >> index.first >> index.second >> operation >> value;

        if (operation == "add" || operation == "a")
        {
            if (puzzle.isAvailable(index, value))
            {
                puzzle.update(index, value);
            }
            else
            {
                std::cout << "ERROR : cannot do the above operation" << std::endl;
            }
        }
        else if (operation == "remove" || operation == "r")
        {
            if (!puzzle.lockedCells[index.first][index.second])
            {
                puzzle.remove(index);
            }
            else
            {
                std::cout << "ERROR : cannot delete an locked cell" << std::endl;
            }
        }
        else if (operation == "quit")
        {
            break;
        }
    }

    if (puzzle.isSolved == bits::solved)
    {
        puzzle.print();

        std::cout << "\n----------------------------------------\n\nCONGRATULATIONS PUZZLE SOLVED\n----------------------------------------\n" << std::endl;
    }

    else
    {
        std::cout << "\n----------------------------------------\n\nFAILED TO SOLVE THE PUZZLE\n----------------------------------------\n\nsolutions :-" << std::endl;
        solution.print();
        std::cout << "\ndifficulty : " << difficulty << std::endl;
    }
    std::cin >> solSeed;

    return 0;
}
