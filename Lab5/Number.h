#pragma once

class Number
{
public:

	// data members
	char* valoare;
	int baza;

	// constructori/destructori

	Number(const char* value, int base); // unde baza e intre 2 si 16
	~Number();

	Number(const Number& n); //contructor de mutare
	Number(Number& n); //constructor de copiere
	Number(const char* s);
	Number(int x);
	Number()
	{
		valoare = nullptr;
		baza = 0;
	}

	// operatori

	friend Number operator + (Number& n1, Number& n2);
	friend Number operator - (Number& n1, Number& n2);
	char* operator += (Number& n);
	char* operator = (Number& n);
	char operator [](int i);
	bool operator < (Number& n);
	bool operator > (Number& n);
	bool operator >= (Number& n);
	bool operator <= (Number& n);
	bool operator == (Number& n);

	// metode

	void SwitchBase(int newBase);
	void Print();
	int  GetDigitsCount(); // returneaza numarul de cifre a numarului curent
	int  GetBase(); // returneaza baza curenta
};