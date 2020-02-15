#include <iostream>
using namespace std;

bool getBit(unsigned int n, int i)
{
    return (n & (1 << i)) > 0;
}

bool isPowerOfTwo(int x)
{
    return (x & (x - 1)) == 0;
}

int getFirstRightBitPosition(int n)
{
    int position = 1;
    while (!getBit(n, position))
    {
        position++;
    }
    return position;
}

int multiply(int first, int second)
{
    int result = 0;
    while (second > 0)
    {
        result += first;
        second--;
    }
    return result;
}

int bitwiseTransform(int x, int y)
{
    int term;
    if (isPowerOfTwo(x))
    {
        term = 27 << getFirstRightBitPosition(x);
    }
    else
    {
        term = multiply(27, x);
    }
    return (term + (y >> 3)) & 3;
}

int referenceTransform(int x, int y)
{
    return (27 * x + (y / 8)) % 4;
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
    int x, y, z;
    cout << "Enter x: ";
    cin >> x;
    cout << "Enter y: ";
    cin >> y;
    z = bitwiseTransform(x, y);
    cout << "Z = " << z << endl;
    cout << "Z = ";
    printHex(z);
    cout << endl;
    cout << "Z = ";
    printBinary(z);
    cout << endl;
    z = referenceTransform(x, y);
    cout << "Z = " << z << endl;
    cout << "Z = ";
    printHex(z);
    cout << endl;
    cout << "Z = ";
    printBinary(z);
    cout << endl;
}