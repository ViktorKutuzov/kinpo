#pragma once
#include <iostream>
#include <string>
#include <map>
#include <fstream>
#include <numeric>
#include <vector>

/*!
*\file
*\brief Данный заголовочный файл содержит в себе описание основных функций, которые используются в программе.
*/

/*!
*\brief Переводит число из римской системы счисления в десятичную
*\param[in] roman - число в римской системе счисления
*\return Число в десятичной системе счисления
*/
/*!
Пример использования функции
*\code
int decimalDigit = romanToInt("XXX"); //decimalDigit = 30
*\endcode
*/
int romanToInt(const std::string& roman);

/*!
*\brief Переводит число из десятичной системы счисления в римскую
*\param[in] number - число в десятичной системе счисления
*\return Число в римской системе счисления
*/
/*!
Пример использования функции
*\code
std::string romanDigit = intToRoman(14); //romanDigit = XIV
*\endcode
*/
std::string intToRoman(const int& number);

/*!
*\brief Разделяет дробь, записанную римской системе счисления, на числитель и знаменатель
*\param[in] romanString - дробь в римской системе счисления
*\param[in, out] romanNumerator - числитель дроби
*\param[in, out] romanDenominator - знаменатиель дроби
*\throw std::runtime_error с указанием ошибки   
*/
/*!
Пример использования функции
*\code
splitFraction("X/I", romanNumerator, romanDenominator); //romanNumerator = X, romanDenominator = I
*\endcode
*/
void splitFraction(std::string romanString, std::string& romanNumerator, std::string& romanDenominator);

/*!
*\brief Главная функция. Проводит сокращение дроби, записанной в римской системе счисления
*\param[in] romanNumerator - числитель дроби
*\param[in] romanDenominator - знаменатиель дроби
*\return Сокращенная дробь в римской системе счисления
*/
/*!
Пример использования функции
*\code
std::string roman = reduceFraction("XXX", "V"); //roman = VI
*\endcode
*/
std::string reduceFraction(std::string& romanNumerator, std::string& romanDenominator);

/*!
*\brief Проверить число на ошибки
*\param[in] roman - римское число
*\return Результат проверки числа
*/
/*!
Пример использования функции
*\code
std::string error = checkNumber("IX"); //error = "", т.к. число правильное
*\endcode
*/
std::string checkNumber(const std::string& roman);