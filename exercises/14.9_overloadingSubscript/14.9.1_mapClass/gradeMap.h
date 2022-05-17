#ifndef GRADEMAP_H_INCLUDED
#define GRADEMAP_H_INCLUDED

#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

struct StudentGrade
{
    std::string s_name{};
    char s_grade{};
};

class GradeMap
{
    private:
    std::vector<StudentGrade> m_map;

    public:
    char& operator[](const std::string& studentName);

};

#endif // GRADEMAP_H_INCLUDED
