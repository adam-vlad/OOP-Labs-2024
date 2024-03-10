#pragma once
#include <string.h>
using namespace std;

class Student
{
    char nume[100];
    float notaMate;
    float notaEngleza;
    float notaIstorie;

public:
    Student();

    void SetareNume(char* numeStudent);
    char* GetNume();

    void SetareNotaMate(float nota);
    float GetNotaMate();

    void SetareNotaEng(float nota);
    float GetNotaEng();

    void SetareNotaIst(float nota);
    float GetNotaIst();

    float GetMediaNot();
};