#include <iostream>

using namespace std;

float operator"" _Fahrenheit(unsigned long long int d)
{
    return (d - 32) / 1.8;
}

float operator"" _Kelvin(unsigned long long int d)
{
    return d - 273.15;
}

int main() {

    float a = 300_Kelvin;
    float b = 120_Fahrenheit;
    cout << a << " " << b;
    return 0;

}