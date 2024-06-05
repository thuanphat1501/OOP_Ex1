/*
* File: main.cpp
* Author: Hong Thuan Phat.
* Date: 3/6/2024.
* Description: This file contains all the functions for the main program.
*/
#include <iostream>
#include <fstream>
#include <string>
#include <list>
#include <algorithm>
#include"student.hpp"
#include"student_operators.hpp"
using namespace std;
/*
* Function: updateCSV.
* Description: This function is call to update CSV file.
* Input:
*    database
* Output:
*   All database will update in CSV file.
*/
void updateCSV(const list<Student>& database) {
    ofstream outputFile("student.csv");
    if (outputFile.is_open()) {
        for (const auto& student : database) {
            outputFile << student.getID() << ","
                << student.getName() << ","
                << student.getGender() << ","
                << student.getAge() << ","
                << student.getMathScore() << ","
                << student.getPhysicsScore() << ","
                << student.getChemistryScore() << endl;
        }
        outputFile.close();
        cout << "CSV file updated successfully." << endl;
    }
    else {
        cout << "Error opening student.csv for writing." << endl;
    }
}
istream& operator>>(istream& in, Gender& gender) {
    int value;
    in >> value;
    gender = static_cast<Gender>(value);
    return in;
}


int main() {
    list<Student> studentDatabase;

    // Load existing student data from CSV file (if any)
    ifstream inputFile("student.csv");
    if (inputFile.is_open()) {
        int id;
        int age;
        string name;
        Gender gender;
        double math, physics, chemistry;
        char comma;

        while (inputFile >> id >> comma >> name >> comma >> age >> comma >> gender >> comma >> math >> comma >> physics >> comma >> chemistry) {
            studentDatabase.emplace_back(name, age, gender, math, physics, chemistry);
        }

        inputFile.close();
    }
    else {
        cout << "No existing student data found." << endl;
    }

    int choice;
    do {
        cout << "1. Add student\n"
            << "2. Delete student\n"
            << "3. Update student information\n"
            << "4. Search for students\n"
            << "5. Student placement\n"
            << "6. Display student list\n"
            << "7. Update CSV file\n"
            << "0. Exit\n"
            << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            addStudent(studentDatabase);
            break;
        case 2:
            int targetID;
            cout << "Enter student ID to delete: ";
            cin >> targetID;
            deleteStudent(studentDatabase, targetID);
            break;
        case 3:
            int updateID;
            cout << "Enter student ID to update: ";
            cin >> updateID;
            updateStudent(studentDatabase, updateID);
            break;
        case 4:
            
            searchStudent(studentDatabase);
            break;
        case 5:
            int sortingOption;
            cout << "Choose sorting option:" << endl;
            cout << "1. Sort by name" << endl;
            cout << "2. Sort by math score" << endl;
            cout << "3. Sort by physics score" << endl;
            cout << "4. Sort by chemistry score" << endl;
            cout << "5. Sort by average score" << endl;
            cout << "Enter your choice (1-5): ";
            cin >> sortingOption;

            sortStudent(studentDatabase, sortingOption);
            break;
        case 6:
            printStudents(studentDatabase);
            break;
        case 7:
            updateCSV(studentDatabase);
            break;
        case 0:
            cout << "Exiting program." << endl;
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 0);

    return 0;
}
