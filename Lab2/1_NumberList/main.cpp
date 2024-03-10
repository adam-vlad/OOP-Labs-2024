#include "NumberList.h"
#include <iostream>

NumberList operatii;

int main()
{
	operatii.Init();

	operatii.Add(9);
	operatii.Print();

	operatii.Add(23);
	operatii.Add(122);
	operatii.Print();

	operatii.Add(233);
	operatii.Add(49);
	operatii.Add(2233);
	operatii.Print();

	operatii.Add(91);
	operatii.Add(2);
	operatii.Add(1);
	operatii.Add(334);

	operatii.Add(197);

	operatii.Sort();
	operatii.Print();

	return 0;
}