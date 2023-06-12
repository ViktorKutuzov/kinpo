/*!
*\file
*\brief Данный  файл содержит в себе реализацию основных функций, которые используются в программе.
*/

#include "functions.h"

const std::unordered_map<char, uint16_t>& dictionary =
{ {'I', 1}, {'V' ,5}, {'X', 10}, {'L', 50}, {'C' ,100}, {'D', 500}, {'M', 1000} }; //Словарь римских цифр

uint16_t romanToInt(const std::string& roman)
{
  uint16_t ans{}; //Переменная для результата

  uint16_t prevValue = dictionary.at(roman[0]);
  for (size_t i = 1; i < roman.size(); ++i) //Для каждого символа в строке roman
  {
    uint16_t currentValue = dictionary.at(roman[i]);

    if (prevValue < currentValue) //Значение текущего символа меньше значения следующего символа
      ans -= prevValue; //Вычесть значение текущего символа из ans
    else
      ans += prevValue; //Иначе добавить значение текущего символа к ans

    prevValue = currentValue; //Сохранить текущее значение как предыдущее для следующей итерации
  }
  ans += prevValue;
  return ans;
}

std::string intToRoman(uint16_t number)
{
  std::string digits[10] { "", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX" }, // Римские цифры для единиц
    tens[10] { "", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC" }, // Римские цифры для десятков
    hundreds[10] { "", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM" }, // Римские цифры сотен
    thousands[4] { "", "M", "MM", "MMM" }; // Римские цифры для тысяч

  std::string result;
  result.reserve(15); // Предполагаемый максимальный размер итоговой строки

  result += thousands[number / 1000];
  result += hundreds[(number % 1000) / 100];
  result += tens[(number % 100) / 10];
  result += digits[number % 10];

  return result; //Вернуть конкатенацию всех римских цифр
}

void splitFraction(std::string romanString, std::string& romanNumerator, std::string& romanDenominator)
{
  if (!romanString.size()) //Проверить наличии входных данных
    throw std::runtime_error("Отсутствуют входные данные.");

  size_t slashIndex = romanString.find('/'); //Проверить наличии символа разделителя
  if (slashIndex == std::string::npos)
    throw std::runtime_error("Отсутствует символ разделителя. Введите числитель, символ разделителя \"/\", знаменатель, не разделяя их пробелами.");

  romanNumerator = romanString.substr(0, slashIndex); //Сохранить числитель дроби
  if (!romanNumerator.size()) //Проверить наличии числителя
    throw std::runtime_error("Отсутствует числитель дроби. Введите числитель, символ разделителя \"/\", знаменатель, не разделяя их пробелами."); \

    romanDenominator = romanString.substr(slashIndex + 1); //Сохранить знаменатель дроби
  if (!romanDenominator.size()) //Проверить наличии знаменателя
    throw std::runtime_error("Отсутствует знаменатель дроби. Введите числитель, символ разделителя \"/\", знаменатель, не разделяя их пробелами.");

  return;
}

std::string checkNumber(const std::string& roman)
{
  if (roman.size() > 15) //Проверить корректность длины
    return "Длина числа не может быть больше 15 символов.";

  for (size_t i{}; i < roman.size(); ++i) //Проверить каждый символ на его присутствие в словаре
    if (dictionary.find(roman[i]) == dictionary.end())
      return ("Cимвол номер " + std::to_string(i + 1) + " неопознан.");

  std::string romanNumber = ""; //Переменная проверки числа
  for (size_t i = 0; i < roman.size(); ++i) //Для каждого символа римского числа;
  {
    romanNumber.push_back(roman[i]); //Добавить символ к переменной romanNumber;

    uint16_t decimalNumber = romanToInt(romanNumber); //Перевести romanNumber в десятичное число;
    if (decimalNumber > 3999 || decimalNumber < 1) //Проверить корректность перевода
    {
      return "Символ " + std::string(1, roman[i]) + ", номер " + std::to_string(i + 1) + " в строке, не может идти после " + roman.substr(0, i);
    }

    if (romanNumber != intToRoman(decimalNumber)) //Проверить получившееся переводом число с частью исходного
    {
      return "Символ " + std::string(1, roman[i]) + ", номер " + std::to_string(i + 1) + " в строке, не может идти после " + roman.substr(0, i);
    }
  }
  return ""; //Вернуть пустую строку, так как ошибка не найдена.
}

std::string reduceFraction(std::string& romanNumerator, std::string& romanDenominator)
{
  // Переводим римские числа в десятичные
  uint16_t numerator = romanToInt(romanNumerator);
  uint16_t denominator = romanToInt(romanDenominator);

  // Находим НОД и сокращаем дробь
  uint16_t divisor = std::gcd(numerator, denominator);
  numerator /= divisor;
  denominator /= divisor;

  // Переводим число в римскую систему счисления
  romanNumerator = intToRoman(numerator);
  romanDenominator = intToRoman(denominator);

  // Создаём новую дробь
  if (romanDenominator == "I")
    return romanNumerator;
  return romanNumerator + "/" + (romanDenominator);
}