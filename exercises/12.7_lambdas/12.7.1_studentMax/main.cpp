#include <iostream>
#include <array>
#include <algorithm>

struct Student
{
    std::string s_name{};
    int s_points{};
};

int main()
{
    std::array<Student, 8> arr
    {
        {   { "Albert", 3 },
            { "Ben", 5 },
            { "Christine", 2 },
            { "Dan", 8 }, // Dan has the most points (8).
            { "Enchilada", 4 },
            { "Francis", 1 },
            { "Greg", 3 },
            { "Hagrid", 5 }
        }
    };

    const auto s {std::max_element(arr.begin(), arr.end(),
    [](const auto &a, const auto &b)
    {
        return a.s_points < b.s_points;
    }
    )};

    std::cout << s->s_name << " is the best student\n";

    return 0;
}
