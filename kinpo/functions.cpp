/*!
*\file
*\brief Данный  файл содержит в себе реализацию основных функций, которые используются в программе.
*/

#include "functions.h"

int romanToInt(const std::string& roman)
{
  int ans{}; //Переменная для результата
  std::map <char, int> dictionary =
  { {'I', 1}, {'V' ,5}, {'X', 10}, {'L', 50}, {'C' ,100}, {'D', 500}, {'M', 1000} }; //Словарь римских цифр

  for (size_t i{}; i < roman.size(); ++i) //Для каждого символа в строке roman
  {
    if ((i + 1 < roman.size()) && (dictionary[roman[i]] < dictionary[roman[i + 1]])) //Значение текущего символа меньше значения следующего символа и текущий символ не является последним
      ans -= dictionary[roman[i]]; //Вычесть значение текущего символа из ans
    else
      ans += dictionary[roman[i]]; //Иначе добавить значение текущего символа к ans
  }

  return ans;
}

std::string intToRoman(const int& number)
{
  std::vector<std::string> digits{ "", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX" }, // Римские цифры для единиц
    tens{ "", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC" }, // Римские цифры для десятков
    hundreds{ "", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM" }, // Римские цифры сотен
    thousands{ "", "M", "MM", "MMM" }; // Римские цифры для тысяч

  return thousands[number / 1000] + hundreds[(number % 1000) / 100] //Вернуть конкатенацию всех римских цифр
    + tens[(number % 100) / 10] + digits[number % 10];
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

  std::map <char, int> dictionary =
  { {'I', 1}, {'V' ,5}, {'X', 10}, {'L', 50}, {'C' ,100}, {'D', 500}, {'M', 1000} }; //Словарь римских цифр

  for (size_t i{}; i < roman.size(); ++i) //Проверить каждый символ на его присутствие в словаре
  {
    if (!dictionary[roman[i]])
    {
      return ("Cимвол номер " + std::to_string(i + 1) + " неопознан.");
    }
  }

  std::string romanNumber = ""; //Переменная проверки числа
  for (size_t i = 0; i < roman.size(); ++i) //Для каждого символа римского числа;
  {
    romanNumber.push_back(roman[i]); //Добавить символ к переменной romanNumber;

    int decimalNumber = romanToInt(romanNumber); //Перевести romanNumber в десятичное число;
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
  int numerator = romanToInt(romanNumerator);
  int denominator = romanToInt(romanDenominator);

  // Находим НОД и сокращаем дробь
  int divisor = std::gcd(numerator, denominator);
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