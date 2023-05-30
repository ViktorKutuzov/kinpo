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
*/

/*!
*\brief ��������� ����� �� ������� ������� ��������� � ����������
*\param[in] roman - ����� � ������� ������� ���������
*\return ����� � ���������� ������� ���������
*/
/*!
������ ������������� �������
*\code
int decimalDigit = romanToInt("XXX"); //decimalDigit = 30
*\endcode
*/
int romanToInt(const std::string& roman);

/*!
*\brief ��������� ����� �� ���������� ������� ��������� � �������
*\param[in] number - ����� � ���������� ������� ���������
*\return ����� � ������� ������� ���������
*/
/*!
������ ������������� �������
*\code
std::string romanDigit = intToRoman(14); //romanDigit = XIV
*\endcode
*/
std::string intToRoman(const int& number);

/*!
*\brief ��������� �����, ���������� ������� ������� ���������, �� ��������� � �����������
*\param[in] romanString - ����� � ������� ������� ���������
*\param[in, out] romanNumerator - ��������� �����
*\param[in, out] romanDenominator - ������������ �����
*\throw std::runtime_error � ��������� ������   
*/
/*!
������ ������������� �������
*\code
splitFraction("X/I", romanNumerator, romanDenominator); //romanNumerator = X, romanDenominator = I
*\endcode
*/
void splitFraction(std::string romanString, std::string& romanNumerator, std::string& romanDenominator);

/*!
*\brief ������� �������. �������� ���������� �����, ���������� � ������� ������� ���������
*\param[in] romanNumerator - ��������� �����
*\param[in] romanDenominator - ������������ �����
*\return ����������� ����� � ������� ������� ���������
*/
/*!
������ ������������� �������
*\code
std::string roman = reduceFraction("XXX", "V"); //roman = VI
*\endcode
*/
std::string reduceFraction(std::string& romanNumerator, std::string& romanDenominator);

/*!
*\brief ��������� ����� �� ������
*\param[in] roman - ������� �����
*\return ��������� �������� �����
*/
/*!
������ ������������� �������
*\code
std::string error = checkNumber("IX"); //error = "", �.�. ����� ����������
*\endcode
*/
std::string checkNumber(const std::string& roman);