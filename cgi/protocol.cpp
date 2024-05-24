#include "sudoku.h"

int main(int argc, char* argv[])
{
    if (argc < 3)
    {
        std::cerr << "seeds are not provided" << std::endl;

        return 1;
    }

    int64_t solSeed = std::stoi(argv[1]);
    int64_t puzzleSeed = std::stoi(argv[2]);

    sudoku puzzle = generateSudoku(solSeed, puzzleSeed, 81);

    sudoku solution;
    std::mt19937 gen(solSeed);
    solution.solve(gen);

    std::cout << puzzle.toString() << " " << solution.toString();

    return 0;
}