// Headers.h
// By: Sophia Moore
// Created on: 11/19/20

struct UndergradStudents
{
    int id_number;
    string first_name;
    string last_name;
    string major;
    double gpa1, gpa2, gpa3, gpa4;

};


void InitializeStructures(UndergradStudents us[], int &size);
// Pre-condition: takes an array and its size
// Post-condition: puts undergrad students info in the array and sorts it by last name
void WriteResults(ofstream &outf, UndergradStudents us[], int size);
// Pre-condition: takes array and its size (and ofstream)
// Post-condition: writes the results in Results.txt
void BubbleSort(UndergradStudents us[], int size);
// Pre-condition: takes an array and its size
// Post-condition: bubble sorts by last name
double AverageGPA(double gpa1, double gpa2, double gpa3, double gpa4);
// Pre-condition: takes 4 gpas (doubles)
// Post-condition: returns the average (also a double)

