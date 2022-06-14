#include <stdio.h>
#include <iostream>
#include <string>
#include <fstream>
#include "Header.h"

using namespace std;

int main(const int argc, char** argv)
{
    setlocale(LC_ALL, "Russian");
    ifstream fin;
    ofstream fout;

    try
    {
        fin.open(".\\input.txt");
        if (fin.is_open()==0)
            throw ("Неверно указан файл с входными данными. Возможно, файл не существует");
        int i = 0;
        int amountOfNumbers=0;
        int numberOfFixedPoints=0;
        string data;
        
        while (!fin.eof() && i < 2)
        {
            fin >> data;
            if (fin.eof() && data.empty())
                throw "Входной файл является пустым.";
            if (i == 0)
                amountOfNumbers = std::stoi(data);
            if (i == 1)
                numberOfFixedPoints = std::stoi(data);
            i++;
        }
        fin.close();
        
        fout.open(".\\output.txt");
        if (fout.is_open() == 0)
            throw "Неверно указан файл для выходных данных. Возможно, указанного расположения не существует";
        try 
        {
            fout << numberOfTranspositionWithFixedPoints(amountOfNumbers, numberOfFixedPoints);
        }
        catch (const int value)
        {
            if (value == 1)
                cout << "Один из операндов не является натуральным числом" << endl;
            if (value == 2)
                cout << "Неверные входные данные: один из операндов не принадлежит диапазону, указанному в требованиях" << endl;
        }
        fout.close();
    }
    catch (const char* e)
    {
        cout << e << endl;
    }

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
    if (amountOfNumbers < 0 || numberOfFixedPoints < 0)
        throw 1;
    if (amountOfNumbers > 9 || numberOfFixedPoints > amountOfNumbers)
        throw 2;
    
    return choiceOfFixedPoints(amountOfNumbers, numberOfFixedPoints) * numberOfTranspositionWithoutFixedPoints(amountOfNumbers - numberOfFixedPoints);
}