#include <iostream>
#include <random>

int main()
{
    int64_t seed = 6969; // Example seed value
    std::mt19937 gen(seed); // Initialize the generator with the seed

    std::uniform_int_distribution<> dis(1, 100); // Define a distribution

    // Generate and print some random numbers
    for (int i = 0; i < 10; ++i)
    {
        int k = dis(gen);

        std::mt19937 g(k);
        std::uniform_int_distribution<> d(1,9);

        std::cout << "seed : " << k << " | value : " << d(g) << std::endl;
    }
    std::cout << std::endl;

    return 0;
}
