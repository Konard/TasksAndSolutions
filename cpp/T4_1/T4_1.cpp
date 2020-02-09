#include <iostream>
#include <cmath>
using namespace std;

double logarithm(double a, double x)
{
    return log(x) / log(a);
}

double F(double b, double c, double x)
{
    return logarithm(5.0 / 11.0, x * x - c) / sqrt(b * tan(1.0 / x * x) - pow(sin(abs(x * sqrt(x))), x / 2));
}

int main()
{
    double pi = 3.14159265358979323846;
    double b = 1.67e-3;
    double c = pi / 3;
    double x = 0.0;
    double a = 0.0;

    cout << "Enter x: ";
    cin >> x;

    cout << "Enter a: ";
    cin >> a;

    cout << "F1(b, c, x) = " << F(b, c, x) << endl;
    cout << "F2(a, x) = " << logarithm(a, x) << endl;
}