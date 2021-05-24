﻿#include <iostream>
#include <string>
#include <ctime>
using namespace std;
string specialitynames[] = { "KN", "TTI", "IN", "ME", "FI" };
enum speciality
{
    KN, IN, ME, FI, TTI
};
struct studentinfo
{
    string LastName;
    int course;
    int Prysicsmark, ITmark, Mathmark;
    speciality Speciality;
};
speciality input(int choice)
{
    speciality output;
    switch (choice)
    {
    case 0: { output = KN; break;   }
    case 1: { output = IN; break;  }
    case 2: { output = ME; break;  }
    case 3: { output = FI; break;  }
    case 4: { output = TTI; break;  }
    default:break;
    }
    return output;
}
void AutoFillInfo(studentinfo* students, const int size)
{
    for (size_t i = 0; i < size; i++)
    {
        cout << "Enter the last name of the student number " << i << " :";
        students[i].LastName = "Petruk";
        //cin >> students[i].LastName;
        students[i].course = rand() % 4 + 1;
        students[i].Prysicsmark = rand() % 4 + 2;
        students[i].Mathmark = rand() % 4 + 2;
        students[i].ITmark = rand() % 4 + 2;
        cout << "the course of the student  is " << students[i].course; cout << endl;
        cout << "the mark in Physics is " << students[i].Prysicsmark;   cout << endl;
        cout << "the mark in Maths is " << students[i].Mathmark;     cout << endl;
        cout << "the mark in IT is " << students[i].ITmark;         cout << endl;
        students[i].Speciality = input(rand() % 5);

        cout << "the speciality is " << specialitynames[students[i].Speciality];         cout << endl;

    }
}
void UserFillInfo(studentinfo* students, const int size)
{
    for (size_t i = 0; i < size; i++)
    {
        cout << "Enter the last name of the student number " << i << " :";
        cin >> students[i].LastName;
        cout << "the course of the student  is "; cin >> students[i].course;
        cout << "the mark in Physics is "; cin >> students[i].Prysicsmark;
        cout << "the mark in Maths is "; cin >> students[i].Mathmark;
        cout << "the mark in IT is "; cin >> students[i].ITmark;
        int choice;
        cout << "the speciality is "; cin >> choice;
        students[i].Speciality = input(choice);
    }
}
void Print(studentinfo* students, const int size)
{
    cout << "№\t|LN\t|Course\t|Speciality\t|Ph\t|IT\t|Maths" << endl;
    for (size_t i = 0; i < size; i++)
    {
        cout << i << "\t|" << students[i].LastName << "\t|" << students[i].course <<
            "\t|\t" << specialitynames[students[i].Speciality] << "\t|" << students[i].Prysicsmark <<
            "\t|" << students[i].ITmark << "\t|" << students[i].Mathmark << endl;
    }
}
void Task1(studentinfo* students, int size)
{
    int k = 0;
    for (size_t i = 0; i < size; i++)
    {
        if (students[i].Mathmark == 5 && students[i].ITmark == 5 && students[i].Prysicsmark == 5)
            k++;
    }
    cout << "Percentage of student who are cons: " << ((float)((float)k / (float)size)) * 100. << "%" << endl;
}
void Task2(studentinfo* students, const int size)
{
    cout << "№\t|LN\t|Course\t|Speciality\t|Ph\t|IT\t|Maths" << endl;
    for (size_t i = 0; i < size; i++)
        if (students[i].Prysicsmark == 5)
        {
            cout << i << "\t|" << students[i].LastName << "\t|" << students[i].course <<
                "\t|\t" << specialitynames[students[i].Speciality] << "\t|" << students[i].Prysicsmark <<
                "\t|" << students[i].ITmark << "\t|" << students[i].Mathmark << endl;
        }
}

void main()
{
    srand(time(NULL));
    int numofstudents;
    cout << "Enter the count of students: "; cin >> numofstudents;
    studentinfo* students = new studentinfo[numofstudents];
    //UserFillInfo(students, numofstudents);
    AutoFillInfo(students, numofstudents);
    Print(students, numofstudents);
    Task1(students, numofstudents);
    Task2(students, numofstudents);


    system("pause");
}