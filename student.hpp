#ifndef __STUDENT_HPP
#define __STUDENT_HPP

/*
* File: student.hpp
* Author: Hong Thuan Phat
* Date: 3/6/2024
* Description: This file contains all the functions/methods for the Student object
*/
#include<string>
using namespace std;
typedef enum Gender
{
    MALE,
    FEMALE
} Gender;

typedef enum Rank
{
    EXCELLENT,
    GOOD,
    AVERAGE,
    WEAK
} Rank;
class Student {
private:
    int studentID;
    string name;
    int age;
    Gender student_gender;
    double mathScore;
    double physicsScore;
    double chemistryScore;

public:
    Student(const string& studentName, int studentAge, Gender gender, double math, double physics, double chemistry)
        : name(studentName), age(studentAge), student_gender(gender), mathScore(math), physicsScore(physics), chemistryScore(chemistry)
    {
        static int ID = 24001;
        studentID = ID;
        ID++;
    }

    int getID() const;
    string getName() const;
    int getAge() const;
    Gender getGender() const;
    double getMathScore() const;
    double getPhysicsScore() const;
    double getChemistryScore() const;
    double getAverage() const;
    Rank getRank();

    void setName(const string& newName);
    void setAge(int newAge);
    void setGender(Gender newGender);
    void setMath(double math);
    void setPhysics(double physics);
    void setChemistry(double chemistry);
};

#endif // !__STUDENT_HPP
