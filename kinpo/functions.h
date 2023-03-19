#pragma once

/*!
ѕереводит число из римской системы счислени€ в дес€тичную
\param[in] roman - римское число
return дес€тичное число
*/
int romanToInt(std::string roman);

/*!
ѕереводит число из дес€тичной системы счислени€ в римскую
\param[in] number - дес€тичное число
\return римское число
*/
std::string intToRoman(int number);

/*!
—окращает дес€тичную дробь
\param[in, out] numerator - числитель дроби
\param[in, out] denominator - знаменатиель дроби
*/
void reduceFraction(int& numerator, int& denominator);

/*!
—оздаЄт дробь в римской системе счислени€
\param[in] romanNumerator - числитель дроби
\param[in] romanDenominator - знаменатиель дроби
\return дробь в римской системе счислени€
*/
std::string createFraction(std::string romanNumerator, std::string romanDenominator);

/*!
–аздел€ет дробь, записанную римской системе счислени€, на числитель и знаменатель
\param[in] romanString дробь в римской системе счислени€
\param[in, out] romanNumerator - числитель дроби
\param[in, out] romanDenominator - знаменатиель дроби
\return
*/
void splitRoman(std::string romanString, std::string& romanNumerator, std::string& romanDenominator);
