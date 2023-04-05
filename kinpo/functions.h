#pragma once

/*!
Переводит число из римской системы счисления в десятичную
\param[in] roman - римское число
return десятичное число
*/
int romanToInt(std::string roman);

/*!
Переводит число из десятичной системы счисления в римскую
\param[in] number - десятичное число
\return римское число
*/
std::string intToRoman(int number);

/*!
Сокращает десятичную дробь
\param[in, out] numerator - числитель дроби
\param[in, out] denominator - знаменатиель дроби
*/
void reduceFraction(int& numerator, int& denominator);

/*!
Создаёт дробь в римской системе счисления
\param[in] romanNumerator - числитель дроби
\param[in] romanDenominator - знаменатиель дроби
\return дробь в римской системе счисления
*/
std::string createFraction(std::string romanNumerator, std::string romanDenominator);

/*!
Разделяет дробь, записанную римской системе счисления, на числитель и знаменатель
\param[in] romanString дробь в римской системе счисления
\param[in, out] romanNumerator - числитель дроби
\param[in, out] romanDenominator - знаменатиель дроби
\return
*/
void splitRoman(std::string romanString, std::string& romanNumerator, std::string& romanDenominator);

/*!
Читает данные из файла
\param[in] - путь к файлу
\param[in, out] - данные
*/
void readFile(std::string path, std::string& data);

/*!
Записывает данные в файл
\param[in] - путь к файлу
\param[in, out] - данные
*/
void writeToFile(std::string path, std::string& data);