#include "gradeMap.h"

char& GradeMap::operator[](const std::string& studentName)
{
    auto found = std::find_if(begin(m_map), end(m_map), [&]
    (const StudentGrade& st)
    {
        return (studentName == st.s_name);
    });

    if (found != end(m_map))
    {
        return found->s_grade;
    }
    else
    {
        m_map.push_back(StudentGrade{studentName, 'A'});
        return m_map.back().s_grade;
    }

}
