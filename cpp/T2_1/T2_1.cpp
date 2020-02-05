#include <iostream>
using namespace std;

unsigned int setBit(unsigned int n, int i, bool value)
{
    return value ? (n | (1 << i)) : (n & ~(1 << i));
}

bool getBit(unsigned int n, int i)
{
    return (n & (1 << i)) > 0;
}

unsigned int transform(unsigned int n)
{
    for (int i = 1; i <= 7; i += 2)
    {
        bool previousBit = getBit(n, i - 1);
        bool currentBit = getBit(n, i);
        n = setBit(n, i, previousBit);
        n = setBit(n, i - 1, currentBit);
    }
    return n;
}

void printBinary(unsigned int n)
{
    int totalBits = sizeof(unsigned int) * 8;
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

void printHex(unsigned int n)
{
    int totalHexDigits = sizeof(unsigned int) * 2;
    bool nonZeroDigitFound = false;
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
    unsigned int n = 0;
    cout << "Enter n: ";
    cin >> n;
    cout << "n = " << n << endl;
    cout << "n in binary = ";
    printBinary(n);
    cout << endl;
    unsigned int result = transform(n);
    cout << "result = " << result << endl;
    cout << "result in binary = ";
    printBinary(result);
    cout << endl;
    cout << "result in hex = ";
    printHex(result);
    cout << endl;
}