#pragma once
/*! 
\param[in] amountOfNumbersWithoutFixedPoints - ���������� �����, �� ���������� ������������ ������
\return ���������� ������������ ��� ����������� �����
*/
int numberOfTranspositionWithoutFixedPoints(int amountOfNumbersWithoutFixedPoints);

/*! ������� ����� ��������� (�������) ���������� ����������� ����� �� ������ ���������� �����
\param[in] totalAmountOfNumbers - ����� ���������� �����
\param[in] numberOfChoicesNumbers - ����� ���������� ����� �� ������ ����������
\return ����� ������� ����������� ����� �� ���� �����
*/
int choiceOfFixedPoints(int totalAmountOfNumbers, int numberOfChoicesNumbers);

/*!
\param[in] amountNumbers - ����� ���������� �����
\param[in] amountFixedPoints - ���������� ����������� �����
\return ������������ ����� ������ ����������� ����� � ����� ������������ ��� ����������� �����
*/
int numberOfTranspositionWithFixedPoints(int amountNumbers, int amountFixedPoints);