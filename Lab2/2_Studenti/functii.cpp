#include "student.h"
#include "functii.h"
#include <iostream>
using namespace std;

int ComparaNume(Student student1, Student student2) {
    if (strcmp(student1.GetNume(), student2.GetNume()) > 0)
        return -1;
    else if (strcmp(student1.GetNume(), student2.GetNume()) == 0)
        return 0;
    else
        return 1;
}

int ComparaNotaMate(Student student1, Student student2) {
    if (student1.GetNotaMate() > student2.GetNotaMate())
        return 1;
    else if (student1.GetNotaMate() == student2.GetNotaMate())
        return 0;
    else
        return -1;
}

int ComparaNotaEng(Student student1, Student student2) {
    if (student1.GetNotaEng() > student2.GetNotaEng())
        return 1;
    else if (student1.GetNotaEng() == student2.GetNotaEng())
        return 0;
    else
        return -1;
}
int ComparaNotaIst(Student student1, Student student2) {
    if (student1.GetNotaIst() > student2.GetNotaIst())
        return 1;
    else if (student1.GetNotaIst() == student2.GetNotaIst())
        return 0;
    else
        return -1;
}
int ComparaMedie(Student student1, Student student2) {
    if (student1.GetMediaNot() > student2.GetMediaNot())
        return 1;
    else if (student1.GetMediaNot() == student2.GetMediaNot())
        return 0;
    else
        return -1;
}