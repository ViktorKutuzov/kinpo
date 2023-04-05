#pragma once

/*!
��������� ����� �� ������� ������� ��������� � ����������
\param[in] roman - ������� �����
return ���������� �����
*/
int romanToInt(std::string roman);

/*!
��������� ����� �� ���������� ������� ��������� � �������
\param[in] number - ���������� �����
\return ������� �����
*/
std::string intToRoman(int number);

/*!
��������� ���������� �����
\param[in, out] numerator - ��������� �����
\param[in, out] denominator - ������������ �����
*/
void reduceFraction(int& numerator, int& denominator);

/*!
������ ����� � ������� ������� ���������
\param[in] romanNumerator - ��������� �����
\param[in] romanDenominator - ������������ �����
\return ����� � ������� ������� ���������
*/
std::string createFraction(std::string romanNumerator, std::string romanDenominator);

/*!
��������� �����, ���������� ������� ������� ���������, �� ��������� � �����������
\param[in] romanString ����� � ������� ������� ���������
\param[in, out] romanNumerator - ��������� �����
\param[in, out] romanDenominator - ������������ �����
\return
*/
void splitRoman(std::string romanString, std::string& romanNumerator, std::string& romanDenominator);

/*!
������ ������ �� �����
\param[in] - ���� � �����
\param[in, out] - ������
*/
void readFile(std::string path, std::string& data);

/*!
���������� ������ � ����
\param[in] - ���� � �����
\param[in, out] - ������
*/
void writeToFile(std::string path, std::string& data);