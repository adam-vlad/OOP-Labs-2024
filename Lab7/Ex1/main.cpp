#include<iostream>

float operator"" _Kelvin(unsigned long long int temp) {
    float t = temp - 273.15f;
    return t;
}

float operator"" _Fahrenheit(unsigned long long int temp) {
    float t = (temp - 32) / 1.8f;
    return t;
}

int main() {
    float a = 300_Kelvin;
    float b = 120_Fahrenheit;

    printf("a: %f \nb: %f", a, b);
    return 0;
}