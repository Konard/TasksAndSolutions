#include <iostream>
using namespace std;

bool getBit(unsigned int n, int i)
{
    return (n & (1 << i)) > 0;
}

void printBinary(unsigned short int n)
{
    int totalBits = sizeof(unsigned short int) * 8;
    bool nonZeroDigitFound = false;
    for (int i = totalBits - 1; i >= 0; i--)
    {
        bool bitIsSet = getBit(n, i);
        if (nonZeroDigitFound || bitIsSet)
        {
            cout << (bitIsSet ? '1' : '0');
            nonZeroDigitFound = true;
        }
    }
}

void printHex(short int n)
{
    int totalHexDigits = sizeof(short int) * 2;
    bool nonZeroDigitFound = false;
    if (n < 0)
    {
        cout << '-';
        n = -n;
    }
    for (int i = totalHexDigits - 1; i >= 0; i--)
    {
        unsigned int digit = (n & (15 << (i * 4))) >> (i * 4);
        if (nonZeroDigitFound || (digit > 0))
        {
            cout << (char)((digit < 10) ? ('0' + digit) : ('A' + digit - 10));
            nonZeroDigitFound = true;   
        }
    }
}

int main()
{
    short int n = -072;
    cout << "-78 in base-8 is " << n << " in base-10." << endl;
    cout << "Two's complement of -78 in base-8 is ";
    printBinary((unsigned short int)n);
    cout << "." << endl;
    cout << "-78 in base-8 is ";
    printHex(n);
    cout << " in base-16." << endl;
}
