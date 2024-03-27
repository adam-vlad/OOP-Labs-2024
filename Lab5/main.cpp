#include <iostream>
#include <stdio.h>
#include "Number.h"

int main()
{
    Number n1("10110010", 2);
    Number n2("734", 8);
    Number n3("FF", 16);

    printf("n1 has %d digits and it is written in base %d\n", n1.GetDigitsCount(), n1.GetBase());
    for (int tr = 0; tr < n1.GetDigitsCount(); tr++)
    {
        printf("n1[%d]=%c\n", tr, n1[tr]);
    }

    n1.Print();
    n2.Print();
    n1 = (n2 + n3 - n1) + n1; // n1 -> baza 16
    n1.SwitchBase(2);
    n1.Print();

    if (n1 > n2)
    {
        printf("n1 is bigger than n2\n");
    }
    else
    {
        printf("n2 is bigger than n1\n");
    }

    Number n4 = 12345; // n4 -> baza10
    n1 = 255; // n1 -> 11111111 (valoarea 255 din baza 10 in baza 2)
    n4 += n1;
    n4.Print();

    n4 = "13579"; // n4 ramane in baza 10 si va fi 13579
    n4.Print();
    --n4; // prima cifra a lui n4 va fi stearsa ==> n4 devine 3579
    n4.Print();
    n4--; // ultima cifra a lui n4 va fi stearsa ==> n4 devine 357
    n4.Print();

    return 0;
}