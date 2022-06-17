#pragma once
/*! 
\param[in] amountOfNumbersWithoutFixedPoints - количество чисел, не являющихся неподвижными точами
\return количество перестановок без неподвижных точек
*/
int numberOfTranspositionWithoutFixedPoints(int amountOfNumbersWithoutFixedPoints);

/*! Находит число сочетаний (выборов) количества неподвижных точек из общего количества чисел
\param[in] totalAmountOfNumbers - общее количество чисел
\param[in] numberOfChoicesNumbers - число выбираемых чисел из общего количества
\return число выборов неподвижных точек из всех чисел
*/
int choiceOfFixedPoints(int totalAmountOfNumbers, int numberOfChoicesNumbers);

/*!
\param[in] amountNumbers - общее количество чисел
\param[in] amountFixedPoints - количество неподвижных точек
\return произведение числа выборо неподвижных точек и числа перестановок без неподвижных точек
*/
int numberOfTranspositionWithFixedPoints(int amountNumbers, int amountFixedPoints);