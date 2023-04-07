#pragma once

/*!
��������� ����� �� ������� ������� ��������� � ����������
\param[in] roman - ������� �����
return ���������� �����
*/
int romanToInt(const std::string& roman);

/*!
��������� ����� �� ���������� ������� ��������� � �������
\param[in] number - ���������� �����
\return ������� �����
*/
std::string intToRoman(const int& number);

/*!
������ ����� � ������� ������� ���������
\param[in] romanNumerator - ��������� �����
\param[in] romanDenominator - ������������ �����
\return ����� � ������� ������� ���������
*/
std::string createFraction(const std::string& romanNumerator, const std::string& romanDenominator);

/*!
��������� �����, ���������� ������� ������� ���������, �� ��������� � �����������
\param[in] romanString ����� � ������� ������� ���������
\param[in, out] romanNumerator - ��������� �����
\param[in, out] romanDenominator - ������������ �����
\return
*/
void splitFraction(std::string romanString, std::string& romanNumerator, std::string& romanDenominator);

/*!
������ ������ �� �����
\param[in] - ���� � �����
\param[in, out] - ������
*/
void readFile(const std::string path, std::string& data);

/*!
���������� ������ � ����
\param[in] - ���� � �����
\param[in, out] - ������
*/
void writeToFile(const std::string path, std::string& data);

/*!
������� �������. �������� ���������� �����
\param[in] numerator - ����� � ������� ������� ���������
\return ����������� �����
*/
std::string reduceFraction(const std::string& roman);