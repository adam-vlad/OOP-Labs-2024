#include "student.h"
#include "functii.h"
#include <iostream>
using namespace std;

int main()
{
    Student student1, student2;

    char nume1[100], nume2[100];
    strcpy_s(nume1, "Dani Smecheru");
    strcpy_s(nume2, "Dani Ionut");

    student1.SetareNume(nume1);
    student1.SetareNotaMate(3.2f);
    student1.SetareNotaEng(2.0f);
    student1.SetareNotaIst(10.0f);

    cout << "Student: " << student1.GetNume() << "\n";
    cout << "Nota Mate: " << student1.GetNotaMate() << "\n";
    cout << "Nota Engleza: " << student1.GetNotaEng() << "\n";
    cout << "Nota Istorie: " << student1.GetNotaIst() << "\n";
    cout << "Media notelor: " << student1.GetMediaNot() << "\n\n";

    student2.SetareNume(nume2);
    student2.SetareNotaMate(10.0f);
    student2.SetareNotaEng(8.3f);
    student2.SetareNotaIst(6.0f);

    cout << "Student: " << student2.GetNume() << "\n";
    cout << "Nota Mate: " << student2.GetNotaMate() << "\n";
    cout << "Nota Engleza: " << student2.GetNotaEng() << "\n";
    cout << "Nota Istorie: " << student2.GetNotaIst() << "\n";
    cout << "Media notelor: " << student2.GetMediaNot() << "\n\n";

    cout << "Comparatie dupa nume: " << ComparaNume(student1, student2) << "\n";
    cout << "Comparatie dupa mate: " << ComparaNotaMate(student1, student2) << "\n";
    cout << "Comparatie dupa engleza: " << ComparaNotaEng(student1, student2) << "\n";
    cout << "Comparatie dupa istorie: " << ComparaNotaIst(student1, student2) << "\n";

    return 0;
}