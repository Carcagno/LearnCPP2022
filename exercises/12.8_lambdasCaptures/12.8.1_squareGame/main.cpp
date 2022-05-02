#include <iostream>
#include <limits>
#include <random>
#include <algorithm>
#include <cmath>

int getInt()
{
    while (true)
    {
        int userNumber {0};
        std::cin >> userNumber;

        if (std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cerr << "Invalid input. Please, try again\n";
        }
        else
        {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            return userNumber;
        }
    }
}


namespace Random // capital R to avoid conflicts with functions named random()
{
	std::mt19937 mt{ std::random_device{}() };

	int get(int min, int max)
	{
		std::uniform_int_distribution die{ min, max }; // we can create a distribution in any function that needs it
		return die(mt); // and then generate a random number from our global generator
	}
}

void fillVectorNumbers(int starter, const int numberToGenerate,
    const int randomMultiplier, std::vector<int>& numbers)
{
    for (int i{0}; i < numberToGenerate; ++i)
    {
        numbers.push_back((starter*starter) * randomMultiplier);
        std::cout << (numbers.back()) << '\n';
        ++starter;
    }
}

int findClosestNumber(const std::vector<int> &numbers, int userAnswer)
{

    return *std::min_element(numbers.begin(), numbers.end(), [=](int a, int b)
    {
        return (std::abs(a - userAnswer) < std::abs(b - userAnswer));
    });
}

int checkOnUserAnswers(std::vector<int> &numbers)
{
    int userAnswer{0};

    for (bool isWrong{false}; !isWrong;)
    {
        isWrong = true;

        userAnswer = getInt();

        auto found{std::find(numbers.begin(), numbers.end(), userAnswer)};

        if (found != numbers.end())
        {
            numbers.erase(found);
            std::cout << "Nice, " << numbers.size() << " numbers left.\n";
            isWrong = false;
        }
        else
        {
            int closestNb {findClosestNumber(numbers, userAnswer)};
            std::cout << userAnswer << " is wrong!";

            if ( std::abs(closestNb - userAnswer) <= 4)
                std::cout << " Try " << closestNb << " next time !\n";
            else
                std::cout << '\n';

        }

    }
}

int main()
{
    int starter{}, numberToGenerate{}, randomMultiplier{Random::get(2, 4)};
    std::vector<int> numbers{};

    std::cout << "Enter the starter number: ";

    starter = getInt();

    std::cout << "Enter the number of numbers to generate: ";

    numberToGenerate = getInt();

    fillVectorNumbers(starter, numberToGenerate, randomMultiplier, numbers);

    std::cout << "I generated " << numberToGenerate
        << "\nDo you know what each number is after multiplying it by 2?\n";

    checkOnUserAnswers(numbers);

    return 0;
}
