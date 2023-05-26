#pragma once
#include <iostream>
#include <string>
#include <map>
#include <fstream>
#include <numeric>
#include <vector>

/*!
\file
\brief ������������ ���� � ��������� �������

������ ���� �������� � ���� ����������� ��������
�������, ������������ � ���������������� ���������
*/

/*!
\file
\brief ������������ ���� � ��������� �������

������ ���� �������� � ����...
*/


/*!
*\fn int romanToInt(const std::string& roman);
*\brief ��������� ����� �� ������� ������� ��������� � ����������
*\param[in] roman - ������� �����
*return ���������� �����
*/
int romanToInt(const std::string& roman);

/*!
*\brief ��������� ����� �� ���������� ������� ��������� � �������
*\param[in] number - ���������� �����
*\return ������� �����
*/
std::string intToRoman(const int& number);

/*!
*��������� �����, ���������� ������� ������� ���������, �� ��������� � �����������
*\param[in] romanString ����� � ������� ������� ���������
*\param[in, out] romanNumerator - ��������� �����
*\param[in, out] romanDenominator - ������������ �����
*\throw ����������� ���������� � ��������� ������� ������
*/
void splitFraction(std::string romanString, std::string& romanNumerator, std::string& romanDenominator);

/*!
*������� �������. �������� ���������� �����
*\param[in] romanNumerator - ��������� �����
*\param[in] romanDenominator - ������������ �����
*\return ����������� �����
*/
std::string reduceFraction(std::string& romanNumerator, std::string& romanDenominator);

/*!
*��������� ����� �� ������
*\param[in] roman - ������� �����
*\return ��������� �������� �����
*/
std::string checkNumber(const std::string& roman);