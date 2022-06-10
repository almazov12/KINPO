#include <stdio.h>
#include <sstream>
#include "Header.h"

using namespace std;

int main(const int argc, char** argv)
{
    printf("%d\n", numberOfTranspositionWithoutFixedPoints(5));
    //printf("%d\n", choiceOfFixedPoints(9, 6));
    //printf("D(%d, %d) = %u\n", 9, 6, numberOfTranspositionWithFixedPoints(9, 6));
    return 0;
}

int numberOfTranspositionWithoutFixedPoints(int amountOfNumbers)
{
    int a = 0, b = 1;
    for (int i = 2; i < amountOfNumbers; i++)
    {
        if (i % 2)
            b = i * (a + b);
        else
            a = i * (a + b);
    }
    return amountOfNumbers % 2 ? a : b;
}

int choiceOfFixedPoints(int amountOfNumbers, int numberOfFixedPoints)
{
    int argumentsDifference = amountOfNumbers - numberOfFixedPoints;
    if (numberOfFixedPoints > argumentsDifference)
        numberOfFixedPoints = argumentsDifference;
    if (!numberOfFixedPoints)
        return 1;
    int multiplicationResult = argumentsDifference = amountOfNumbers - numberOfFixedPoints + 1;
    argumentsDifference++;
    for (int i = 2; i <= numberOfFixedPoints; i++, argumentsDifference++)
        multiplicationResult = multiplicationResult / i * argumentsDifference + multiplicationResult % i * argumentsDifference / i;
    return multiplicationResult;
}

int numberOfTranspositionWithFixedPoints(int amountOfNumbers, int numberOfFixedPoints)
{
    return choiceOfFixedPoints(amountOfNumbers, numberOfFixedPoints) * numberOfTranspositionWithoutFixedPoints(amountOfNumbers - numberOfFixedPoints);
}