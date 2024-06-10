#include "sudoku.h"

sudoku generatePuzzle(int64_t seed, int ratingStartPoint, int ratingEndPoint);

int main()
{
    int64_t seed;
    std::cout << "enter seed : ";
    std::cin >> seed;

    int startRating, endRating;
    std::cout << "enter puzzle rating range (starting range, end range) : ";
    std::cin >> startRating >> endRating;

    sudoku puzzle = generatePuzzle(seed,startRating,endRating);
    puzzle.lockCells();
    int difficulty = puzzle.difficulty();

    sudoku solution = puzzle;
    std::mt19937 gen(69);
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
    std::cin >> seed;

    return 0;
}
