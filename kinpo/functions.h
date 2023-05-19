#pragma once
#include <iostream>
#include <string>
#include <map>
#include <fstream>
#include <numeric>
#include <vector>

/*!
Переводит число из римской системы счисления в десятичную
\param[in] roman - римское число
\param[in, out] errors - массив содержащий сообщения об ошибках
\throw - (Выбрасывает исключения в ошибочных входных данных)
return десятичное число
*/
int romanToInt(const std::string& roman);

/*!
Переводит число из десятичной системы счисления в римскую
\param[in] number - десятичное число
\return римское число
*/
std::string intToRoman(const int& number);

/*!
Разделяет дробь, записанную римской системе счисления, на числитель и знаменатель
\param[in] romanString дробь в римской системе счисления
\param[in, out] romanNumerator - числитель дроби
\param[in, out] romanDenominator - знаменатиель дроби
\throw - (Выбрасывает исключения в ошибочных входных данных)
*/
void splitFraction(std::string romanString, std::string& romanNumerator, std::string& romanDenominator);

/*!
Читает данные из файла
\param[in] - путь к файлу
\param[in, out] - данные
*/
void readFile(const std::string path, std::string& data);

/*!
Записывает данные в файл
\param[in] - путь к файлу
\param[in, out] - данные
*/
void writeToFile(const std::string path, std::string& data);

/*!
Главная функция. Проводит сокращение дроби
\param[in] roman - дробь в римской системе счисления
\return сокращенная дробь
\throw - (Выбрасывает исключения в ошибочных входных данных)
*/

std::string reduceFraction(std::string& romanNumerator, std::string& romanDenominator);

/*!
Проверить число на ошибки
\param[in] roman - римское число
\return результат проверки числа
*/
std::string checkNumber(const std::string& roman);