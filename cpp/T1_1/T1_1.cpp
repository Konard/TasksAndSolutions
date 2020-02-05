#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

double FExact(const double x, const int m)
{
    double initialExpression = 1 + x;
    double resultAccumulator = 1;
    if (m > 0)
    {
        for (int i = 0; i < m; i++)
        {
            resultAccumulator *= initialExpression;
        }
    }
    else if (m < 0)
    {
        for (int i = 0; i > m; i--)
        {
            resultAccumulator /= initialExpression;
        }
    }
    return resultAccumulator;
}

double FDecomposition(const double x, const double m, const int maxN = 7)
{
    double resultAccumulator = 1.0;
    double initialSignModifier = -1.0;
    double initialDenominator = 1.0;
    double signModifier = 1.0;
    double numeratorAccumulator = 1.0;
    double denominatorAccumulator = 1.0;
    for (int n = 1; n <= maxN; n++)
    {
        numeratorAccumulator *= x;
        numeratorAccumulator *= (-m + n - 1.0);
        denominatorAccumulator *= n;
        signModifier *= initialSignModifier;
        resultAccumulator += signModifier * (numeratorAccumulator / denominatorAccumulator);
    }
    return resultAccumulator;
}

void initArraysWithFunctionValues(const int m, double exactValues[], double decompositionValues[])
{
    int i = 0;
    for (double x = -0.9; x <= 0.9; i++, x += 0.1)
    {
        exactValues[i] = FExact(x, m);
        decompositionValues[i] = FDecomposition(x, m);
    }
}

void calculateDifferences(const int arraysSize, double exactValues[], double decompositionValues[], double differences[])
{
    for (int i = 0; i < arraysSize; i++)
    {
        differences[i] = exactValues[i] - decompositionValues[i];
    }
}

int main()
{
    const int arraysSize = 19;
    const int m = -4;
    double exactValues[arraysSize];
    double decompositionValues[arraysSize];
    initArraysWithFunctionValues(m, exactValues, decompositionValues);
    double differences[arraysSize];
    calculateDifferences(arraysSize, exactValues, decompositionValues, differences);

    std::cout << std::setfill(' ') << std::setw(20) << "exact" << ' ';
    std::cout << std::setfill(' ') << std::setw(20) << "decomposition" << ' ';
    std::cout << std::setfill(' ') << std::setw(20) << "difference" << std::endl;

    for (int i = 0; i < arraysSize; i++)
    {
        std::cout << std::setfill(' ') << std::setw(20) << exactValues[i] << ' ';
        std::cout << std::setfill(' ') << std::setw(20) << decompositionValues[i] << ' ';
        std::cout << std::setfill(' ') << std::setw(20) << differences[i] << std::endl;
    }
}