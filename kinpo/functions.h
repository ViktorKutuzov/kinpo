#pragma once
#include <iostream>
#include <string>
#include <map>
#include <fstream>
#include <numeric>
#include <vector>

/*!
��������� ����� �� ������� ������� ��������� � ����������
\param[in] roman - ������� �����
\param[in, out] errors - ������ ���������� ��������� �� �������
\throw - (����������� ���������� � ��������� ������� ������)
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
��������� �����, ���������� ������� ������� ���������, �� ��������� � �����������
\param[in] romanString ����� � ������� ������� ���������
\param[in, out] romanNumerator - ��������� �����
\param[in, out] romanDenominator - ������������ �����
\throw - (����������� ���������� � ��������� ������� ������)
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
\param[in] roman - ����� � ������� ������� ���������
\return ����������� �����
\throw - (����������� ���������� � ��������� ������� ������)
*/

std::string reduceFraction(std::string& romanNumerator, std::string& romanDenominator);

/*!
��������� ����� �� ������
\param[in] roman - ������� �����
\return ��������� �������� �����
*/
std::string checkNumber(const std::string& roman);