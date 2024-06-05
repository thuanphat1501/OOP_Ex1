#ifndef __STUDENT_OPERATORS_HPP
#define __STUDENT_OPERATORS_HPP
#include<list>
#include"student.hpp"
void addStudent(list<Student>& database);
void deleteStudent(list<Student>& database, int targetID);
void updateStudent(list<Student>& database, int targetID);
void sortStudent(list<Student>& database, int sortingOption);
void searchStudent(const list<Student>& database);
void printStudents(const list<Student>& database);
//void updateCSV(const list<Student>& database);
#endif // !__STUDENT_OPERATORS_HPP
