#pragma once
#include <iostream>
#include <string>
#include <map>
#include <fstream>
#include <numeric>
#include <vector>


/*!
*\file
*\brief ������ ������������ ���� �������� � ���� �������� �������� �������, ������� ������������ � ���������.
*\author Viktor Kutuzov
*\mainpage [(title)]
*/

/*!
*\brief ��������� ����� �� ������� ������� ��������� � ����������
*\param[in] roman - ����� � ������� ������� ���������
*\return ����� � ���������� ������� ���������
*/
int romanToInt(const std::string& roman);

/*!
*\brief ��������� ����� �� ���������� ������� ��������� � �������
*\param[in] number - ����� � ���������� ������� ���������
*\return ����� � ������� ������� ���������
*/
std::string intToRoman(const int& number);

/*!
*\brief ��������� �����, ���������� ������� ������� ���������, �� ��������� � �����������
*\param[in] romanString - ����� � ������� ������� ���������
*\param[in, out] romanNumerator - ��������� �����
*\param[in, out] romanDenominator - ������������ �����
*\throw ����������� ���������� � ��������� ������� ������
*/
void splitFraction(std::string romanString, std::string& romanNumerator, std::string& romanDenominator);

/*!
*\brief ������� �������. �������� ���������� �����, ���������� � ������� ������� ���������
*\param[in] romanNumerator - ��������� �����
*\param[in] romanDenominator - ������������ �����
*\return ����������� ����� � ������� ������� ���������
*/
std::string reduceFraction(std::string& romanNumerator, std::string& romanDenominator);

/*!
*\brief ��������� ����� �� ������
*\param[in] roman - ������� �����
*\return ��������� �������� �����
*/
std::string checkNumber(const std::string& roman);