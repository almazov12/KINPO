#include <stdio.h>
#include <iostream>
#include <string>
#include <fstream>
#include "Header.h"

using namespace std;

int main(const int argc, char** argv)
{
    ifstream fin;
    ofstream fout;

    fin.open("input.txt");
    int i = 0;
    int amountOfNumbers = 0;
    int numberOfFixedPoints = 0;
    string data;
    if (fin.is_open()) {
        while (!fin.eof() && i < 2)
        {
            fin >> data;
            if (i == 0)
                amountOfNumbers = std::stoi(data);
            if (i == 1)
                numberOfFixedPoints = std::stoi(data);
            i++;
        }
    }
    fin.close();

    fout.open("output.txt");

    if (fout.is_open()) {
        fout << numberOfTranspositionWithFixedPoints(amountOfNumbers, numberOfFixedPoints);
    }
    fout.close();

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