#include <iostream>
#include <limits>
#include <vector>
#include <algorithm>

#include "students.h"

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

bool my_compare(const Students& a, const Students& b)
{
    return a.s_grade > b.s_grade;
}

void printStudents(const std::vector<Students>& sv)
{
    for (Students s : sv)
    {
        std::cout << s.s_name << " got a grade of " << s.s_grade << '\n';
    }
}

std::vector<Students> getStudents()
{
    int numberOfStudents {getInt()};
    std::vector<Students> students;

    for (int i{}; i < numberOfStudents; ++i)
    {
        Students s{};
        std::cout << "Name of student #" << i+1 << ": ";
        std::getline(std::cin >> std::ws, s.s_name);

        std::cout << "Grade of student #" << i+1 << ": ";
        s.s_grade = getInt();
        students.push_back(s);
    }

    return students;
}

int main()
{
    std::cout << "Enter the number of students you want to record: ";
    std::vector<Students> students{getStudents()};

    std::sort (students.begin(), students.end(), my_compare);

    printStudents(students);

    return 0;
}
