#include "student.h"
#include <iostream>
using namespace std;

Student::Student()
{
    notaMate = 0.0f;
    notaEngleza = 0.0f;
    notaIstorie = 0.0f;
}

void Student::SetareNume(char* numeStudent) {
    strcpy_s(nume, numeStudent);
}

char* Student::GetNume() {
    return nume;
}

void Student::SetareNotaMate(float nota) {
    notaMate = nota;
}

float Student::GetNotaMate() {
    return notaMate;
}

void Student::SetareNotaEng(float nota) {
    notaEngleza = nota;
}

float Student::GetNotaEng() {
    return notaEngleza;
}

void Student::SetareNotaIst(float nota) {
    notaIstorie = nota;
}

float Student::GetNotaIst() {
    return notaIstorie;
}

float Student::GetMediaNot() {
    return (notaMate + notaEngleza + notaIstorie) / 3.0f;
}