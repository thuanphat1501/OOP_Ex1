/*
* File: student.cpp
* Author: Hong Thuan Phat.
* Date: 3/6/2024.
* Description: This file contains all the functions for the Student object.
*/
#include<iostream>
#include<string>
#include"student.hpp"
/*
* Function: getAverage.
* Description: This function will return the average value.
* Input: None
* Output:
*   Returns the average of 3 score.
*/
double Student::getAverage() const
{
	return (mathScore + physicsScore + chemistryScore) / 3;
}
/*
* Function: getRank.
* Description: This function will return the rank of student.
* Input: None
* Output:
*   Returns the rank of student.
*/
Rank Student::getRank()
{
	if (getAverage() >= 8)
	{
		return Rank::EXCELLENT;
	}
	else if (getAverage() >= 6.5)
	{
		return Rank::GOOD;
	}
	else if (getAverage() >= 5.0)
	{
		return Rank::AVERAGE;
	}
	else
	{
		return Rank::WEAK;
	}
}
/*
* Function: getID.
* Description: This function will return the ID of student.
* Input: None
* Output:
*   Returns the ID of student.
*/
int Student::getID() const { return studentID; }
/*
* Function: getName.
* Description: This function will return the name of student.
* Input: None
* Output:
*   Returns the name of student.
*/
string Student::getName() const { return name; }
/*
* Function: getAge.
* Description: This function will return the age of student.
* Input: None
* Output:
*   Returns the age of student.
*/
int Student::getAge() const { return age; }
/*
* Function: getGender.
* Description: This function will return the gender of student.
* Input: None
* Output:
*   Returns the gender of student.
*/
Gender Student::getGender() const { return student_gender; }
/*
* Function: getMathScore.
* Description: This function will return the math score of student.
* Input: None
* Output:
*   Returns the math score of student.
*/
double Student::getMathScore() const { return mathScore; }
/*
* Function: getPhysicsScore.
* Description: This function will return the physics score of student.
* Input: None
* Output:
*   Returns the physics score of student.
*/
double Student::getPhysicsScore() const { return physicsScore; }
/*
* Function: getChemistryScore.
* Description: This function will return the Chemistry Score of student.
* Input: None
* Output:
*   Returns the Chemistry Score of student.
*/
double Student::getChemistryScore() const { return chemistryScore; }

/*
* Function: setName.
* Description: This function will return the new name of student.
* Input: newName.
* Output:
*   Returns the new name of student.
*/
void Student::setName(const string& newName) { name = newName; }
/*
* Function: setAge.
* Description: This function will return the new age of student.
* Input: newAge.
* Output:
*   Returns the new age of student.
*/
void Student::setAge(int newAge) { age = newAge; }
/*
* Function: setGender.
* Description: This function will return the new gender of student.
* Input: newGender.
* Output:
*   Returns the new gender of student.
*/
void Student::setGender(Gender newGender) { student_gender = newGender; }
/*
* Function: setMath.
* Description: This function will return the new math score of student.
* Input: math.
* Output:
*   Returns the new math score of student.
*/
void Student::setMath(double math) { mathScore = math; }
/*
* Function: setPhysics.
* Description: This function will return the new physics score of student.
* Input: physics.
* Output:
*   Returns the new physics score of student.
*/
void Student::setPhysics(double physics) { physicsScore = physics; }
/*
* Function: setChemistry.
* Description: This function will return the new chemistry score of student.
* Input: chemistry.
* Output:
*   Returns the new chemistry score of student.
*/
void Student::setChemistry(double chemistry) { chemistryScore = chemistry; }