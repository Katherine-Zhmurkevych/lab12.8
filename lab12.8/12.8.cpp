#include <stdio.h> 
#include <stdlib.h>
#include<iostream>
#include <string>
#include<list>
#include <string.h>

using namespace std;

struct Student {
    std::string surname;
    double averageScore;
    int bursary;
};

string toString(Student item) {
    return "Surname: " + item.surname + " average score: " + to_string(item.averageScore) + " bursary: " + to_string(item.bursary);
}

void printList(list<Student>& students) {
    std::cout << "Actual students list: \n";
    for (auto iter = students.begin(); iter != students.end(); iter++)
    {
        Student currentStudent = *iter;
        std::cout << toString(currentStudent) << "\n";
    }
    std::cout << std::endl;
}

void findStudentByScore(list<Student>& students, double score) {
    std::cout << "Search result. Students that have " << to_string(score) << " average score." << endl;
    for (auto iter = students.begin(); iter != students.end(); iter++)
    {
        Student currentStudent = *iter;
        if (currentStudent.averageScore == score) {
            std::cout << toString(currentStudent) << "\n";
        }
    }
}

list<Student> dropLosers(list<Student>& students) {
    for (auto iter = students.begin(); iter != students.end(); iter++)
    {
        Student currentStudent = *iter;
        if (currentStudent.bursary == 0) {
            iter = students.erase(iter);

            std::cout << "Removed student wihout bursary: \n" << toString(currentStudent) << "\n";
        }
    }
    return students;
}


int main()
{
    Student firstStudent;
    Student secondStudent;
    Student thirdStudent;
    Student forthStudent;
    Student fifthStudent;
    Student sixthStudent;

    firstStudent.surname = "Ivanenko";
    firstStudent.averageScore = 3.7;
    firstStudent.bursary = 1200;

    secondStudent.surname = "Petrenko";
    secondStudent.averageScore = 4.2;
    secondStudent.bursary = 1200;

    thirdStudent.surname = "Serhijenko";
    thirdStudent.averageScore = 4.9;
    thirdStudent.bursary = 1500;

    forthStudent.surname = "Vasko";
    forthStudent.averageScore = 4.2;
    forthStudent.bursary = 1450;

    fifthStudent.surname = "Datsuk";
    fifthStudent.averageScore = 3.1;
    fifthStudent.bursary = 0;

    sixthStudent.surname = "Gavrylo";
    sixthStudent.averageScore = 4.2;
    sixthStudent.bursary = 1350;

    std::list<Student> listOfStudent;

    listOfStudent.push_back(firstStudent);
    listOfStudent.push_back(secondStudent);
    listOfStudent.push_back(thirdStudent);
    listOfStudent.push_back(forthStudent);
    listOfStudent.push_back(fifthStudent);
    listOfStudent.push_back(sixthStudent);
    printList(listOfStudent);

    long double score;
    std::cout << "Insert average score please:"; std::cin >> score;
    findStudentByScore(listOfStudent, score);
    list<Student> adjustedStudents = dropLosers(listOfStudent);
    printList(adjustedStudents);

    return 0;
}