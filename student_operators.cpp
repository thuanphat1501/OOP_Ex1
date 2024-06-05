/*
* File: student_operators.cpp
* Author: Hong Thuan Phat.
* Date: 3/6/2024.
* Description: This file contains all the functions for the Student object.
*/

#include<list>
#include <fstream>
#include<iostream>
#include"student.hpp"
using namespace std;
/*
* Function: addStudent.
* Description: This function is call to add one student to database.
* Input:
*   database 
* Output:
*   Add 1 student to the database.
*/
void addStudent(list<Student>& database) {
    string name;
    int age;
    Gender gender;
    double math, physics, chemistry;

    cout << "Enter student name: ";
    cin.ignore(); // Clear newline character from previous input
    getline(cin, name);
    cout << "Enter age: ";
    cin >> age;
    int g;
    do
    {
        cout << "Enter gender: (0 - MALE / 1 - FEMALE)" << endl;
        cin >> g;
        if (g == 0)
        {
            gender = MALE;
        }
        else if (g == 1)
        {
            gender = FEMALE;
        }
    } while (g != 0 && g != 1);
    cout << "Enter math score: ";
    cin >> math;
    cout << "Enter physics score: ";
    cin >> physics;
    cout << "Enter chemistry score: ";
    cin >> chemistry;
    Student sv(name, age, gender, math, physics, chemistry);
    database.emplace_back(sv);
    cout << "----------------------" << "\n";
    cout << "ID: " << sv.getID() << "\n";
    cout << "Name: " << name << "\n";
    cout << "Age: " << age << "\n";
    cout << "Gender: " << gender << "\n";
    cout << "Math Score: " << math << "\n";
    cout << "Physic Score: " << physics << "\n";
    cout << "Chemical Score: " << chemistry << "\n";
    cout << "    Math Score	|  Physic Score |  Chemical Score" << "\n";
    cout << '\t' << math << '\t' << '\t' << physics << '\t' << '\t' << chemistry << "\n";
    cout << "Average:" << sv.getAverage() << "\n";
    cout << "Rank:" << sv.getRank() << "\n";
}
/*
* Function: deleteStudent.
* Description: This function is call to delete one student to database.
* Input:
*    database
*    targetID : ID value want to delete.
* Output:
*   Delete 1 student to the database.
*/
void deleteStudent(list<Student>& database, int targetID) {
    auto it = database.begin();
    while (it != database.end()) {
        if (it->getID() == targetID) {
            cout << "Student with ID " << targetID << " has been deleted." << endl;
            it = database.erase(it);
            return;
        }
        else {
            ++it;
        }
    }
    cout << "Student with ID " << targetID << " not found." << endl;
}
/*
* Function: updateStudent.
* Description: This function is call to delete one student to database.
* Input:
*    database
*    targetID : ID value want to update.
* Output:
*   Update 1 student to the database.
*/
void updateStudent(list<Student>& database, int targetID) {
	for (auto& student : database) {
		if (student.getID() == targetID) {
			cout << "Choose information to update:\n";
			cout << "1. Name\n";
			cout << "2. Age\n";
			cout << "3. Gender\n";
            cout << "4. Math Score\n";
            cout << "5. Physics Score\n";
            cout << "6. Chemical Score\n";
			int choice;
			cin >> choice;

			switch (choice) {
			case 1: {
				cout << "Enter new name: ";
				cin.ignore(); // Xóa ký tự '\n' còn lại trong bộ đệm
				string newName;
				getline(cin, newName);
				student.setName(newName);
				break;
			}
			case 2: {
				cout << "Enter new age: ";
				int newAge;
				cin >> newAge;
				student.setAge(newAge);
				break;
			}
			case 3: {
				cout << "Enter new gender ('M' hoặc 'F'): ";
				char newGender;
				cin >> newGender;
				if (newGender == 'M' || newGender == 'm') {
					student.setGender(MALE);
				}
				else if (newGender == 'F' || newGender == 'f') {
					student.setGender(FEMALE);
				}
				else {
					cout << "Gender ERROR!!!.\n";
				}
				break;
			}
            case 4: {
                cout << "Enter new Math Score: ";
                int newMath;
                cin >> newMath;
                student.setMath(newMath);
                break;
            }
            case 5: {
                cout << "Enter new Physics Score: ";
                int newPhysics;
                cin >> newPhysics;
                student.setPhysics(newPhysics);
                break;
            }
            case 6: {
                cout << "Enter new Chemical Score: ";
                int newChemical;
                cin >> newChemical;
                student.setChemistry(newChemical);
                break;
            }
			default:
				cout << "ERORR!!!.\n";
				break;
			}


			return; 
		}
	}
	
	cout << "Cant find student with ID " << targetID << ".\n";
}
/*
* Function: compareByName.
* Description: This function is call to comparator function for sorting by student name.
* Input:
*    student 1
*    student 2
* Output:
*   Comparator function for sorting by student name.
*/
bool compareByName(const Student& s1, const Student& s2) {
    return s1.getName() < s2.getName();
}
/*
* Function: compareByMathScore.
* Description: This function is call to comparator function for sorting by math score.
* Input:
*    student 1
*    student 2
* Output:
*   Comparator function for sorting by math score.
*/
bool compareByMathScore(const Student& s1, const Student& s2) {
    return s1.getMathScore() > s2.getMathScore();
}
/*
* Function: compareByPhysicsScore.
* Description: This function is call to comparator function for sorting by physics score.
* Input:
*    student 1
*    student 2
* Output:
*   Comparator function for sorting by physics score.
*/
bool compareByPhysicsScore(const Student& s1, const Student& s2) {
    return s1.getPhysicsScore() > s2.getPhysicsScore();
}
/*
* Function: compareByChemistryScore.
* Description: This function is call to comparator function for sorting by chemistry score.
* Input:
*    student 1
*    student 2
* Output:
*   Comparator function for sorting by chemistry score.
*/
bool compareByChemistryScore(const Student& s1, const Student& s2) {
    return s1.getChemistryScore() > s2.getChemistryScore();
}
/*
* Function: compareByAverageScore.
* Description: This function is call to comparator function for sorting by average score.
* Input:
*    student 1
*    student 2
* Output:
*   Comparator function for sorting by average score.
*/
bool compareByAverageScore(const Student& s1, const Student& s2) {
    return s1.getAverage() > s2.getAverage();
}
/*
* Function: sortStudent.
* Description: This function is call to comparator function for sorting by sorting option.
* Input:
*    database
*    sortingOption
* Output:
*   Comparator function for sorting by sorting option.
*/
void sortStudent(list<Student>& database, int sortingOption) {
    switch (sortingOption) {
    case 1:
        database.sort(compareByName);
        cout << "Sorted by student name." << endl;
        break;
    case 2:
        database.sort(compareByMathScore);
        cout << "Sorted by math score." << endl;
        break;
    case 3:
        database.sort(compareByPhysicsScore);
        cout << "Sorted by physics score." << endl;
        break;
    case 4:
        database.sort(compareByChemistryScore);
        cout << "Sorted by chemistry score." << endl;
        break;
    case 5:
        database.sort(compareByAverageScore);
        cout << "Sorted by average score." << endl;
        break;
    default:
        cout << "Invalid sorting option." << endl;
    }
    // Print the sorted list
    for (const auto& student : database) {
        cout << "ID: " << student.getID()
            << ", Name: " << student.getName()
            << ", Age: " << student.getAge()
            << ", Gender: " << (student.getGender() == MALE ? "Male" : "Female")
            << ", Math Score: " << student.getMathScore()
            << ", Physics Score: " << student.getPhysicsScore()
            << ", Chemistry Score: " << student.getChemistryScore()
            << ", Average: " << student.getAverage()
            << endl;
    }
}
/*
* Function: searchStudent.
* Description: This function is call to search student in database.
* Input:
*    database
* Output:
*   The list will print out by ID or name.
*/
void searchStudent(const list<Student>& database) {
    int choice;
    cout << "Choose a search method:" << endl;
    cout << "1. Search for ID." << endl;
    cout << "2. Search for name." << endl;
    cout << "Enter your choice (1 or 2): ";
    cin >> choice;

    string searchValue;
    cout << "Enter search value: ";
    cin >> searchValue;

    list<Student> matchingStudents; // Danh sách lưu trữ các sinh viên phù hợp

    for (const auto& student : database) {
        if ((choice == 1 && to_string(student.getID()) == searchValue) ||
            (choice == 2 && student.getName() == searchValue)) {
            matchingStudents.push_back(student); // Thêm sinh viên vào danh sách
        }
    }

    if (!matchingStudents.empty()) {
        cout << "The students were found:" << endl;
        for (const auto& student : matchingStudents) {
            cout << "----------------------------------------" << "\n"
                 << "ID: " << student.getID()
                << ", Name: " << student.getName()
                << ", Age: " << student.getAge()
                << ", Gender: " << (student.getGender() == MALE ? "Male" : "Female")
                << ", Math Score: " << student.getMathScore()
                << ", Physics Score: " << student.getPhysicsScore()
                << ", Chemistry Score: " << student.getChemistryScore()
                << ", Average: " << student.getAverage()
                << "----------------------------------------" << "\n"
                << endl;
        }
    }
    else {
        cout << "No students found." << endl;
    }
}
/*
* Function: printStudents.
* Description: This function is call to display all student in database.
* Input:
*    database
* Output:
*   All list will print out.
*/
void printStudents(const list<Student>& database) {
    cout << "Student List:" << endl;
    for (const auto& student : database) {
        cout << "----------------------------------------" << "\n"
            << "ID: " << student.getID()
            << ", Name: " << student.getName()
            << ", Age: " << student.getAge()
            << ", Gender: " << (student.getGender() == MALE ? "Male" : "Female")
            << ", Math Score: " << student.getMathScore()
            << ", Physics Score: " << student.getPhysicsScore()
            << ", Chemistry Score: " << student.getChemistryScore()
            << ", Average: " << student.getAverage()
            << "----------------------------------------" << "\n"
            << endl;
    }
}
