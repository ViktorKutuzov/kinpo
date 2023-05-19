#include "functions.h"

int main (int argc, char* argv[])
{
  try
  {
    //if (argv[1] == NULL || argv[2] == NULL) 
    //{
    //    throw std::exception("Не указаны расположения файлов с входными и выходными данными.");
    //}

    std::string roman = {};
    std::string inpath = "input.txt";
    std::string outpath = "output.txt";

    readFile(inpath, roman);

    // Переменные для числителя и знаменателя
    std::string romanNumerator = {};
    std::string romanDenominator = {};

    // Разделяем дробь на числитель и знаменатель
    splitFraction(roman, romanNumerator, romanDenominator);

    std::cout << "Числитель дроби содержит следующие ошибки в записи:" << std::endl;


    std::string result = reduceFraction(romanNumerator, romanDenominator);

    writeToFile(outpath, result);

    return 0;
  }

  catch (const std::exception& ex)
  {
    std::cout << ex.what() << std::endl;
  }
  catch (...)
  {

  }
}

int romanToInt(const std::string& roman)
{
  int ans{};
  std::map <char, int> dictionary =
  { {'I', 1}, {'V' ,5}, {'X', 10}, {'L', 50}, {'C' ,100}, {'D', 500}, {'M', 1000} };

  for (size_t i{}; i < roman.size(); ++i)
  {
    if ((i + 1 < roman.size()) && (dictionary[roman[i]] < dictionary[roman[i + 1]]))
      ans -= dictionary[roman[i]];
    else
      ans += dictionary[roman[i]];
  }

  return ans;
}

std::string intToRoman(const int& number)
{
  std::vector<std::string> digits { "", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX" },
  tens                            { "", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC" },
  hundreds                        { "", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM" },
  thousands                       { "", "M", "MM", "MMM" };

  return thousands[number / 1000] + hundreds[(number % 1000) / 100]
    + tens[(number % 100) / 10] + digits[number % 10];
}

void splitFraction(std::string romanString, std::string& romanNumerator, std::string& romanDenominator)
{
  if (!romanString.size())
    throw std::exception("Отсутствуют входные данные.");

  size_t slashIndex = romanString.find('/');
  if (slashIndex == std::string::npos)
    throw std::exception("Отсутствует символ разделителя. Введите числитель, символ разделителя \"/\", знаменатель, не разделяя их пробелами.");

  romanNumerator = romanString.substr(0, slashIndex);
  if (!romanNumerator.size())
    throw std::exception("Отсутствует числитель дроби. Введите числитель, символ разделителя \"/\", знаменатель, не разделяя их пробелами.");\

  romanDenominator = romanString.substr(slashIndex + 1);
  if (!romanDenominator.size())
    throw std::exception("Отсутствует знаменатель дроби. Введите числитель, символ разделителя \"/\", знаменатель, не разделяя их пробелами.");

  return;
}

void readFile(const std::string path, std::string& data)
{
  std::ifstream input;
  input.open(path);
  if (!input.is_open())
  {
    throw std::exception("Неверно указан файл с входными данными. Возможно, файл не существует.");
  }
  else
  {
    input >> data;
  }
  input.close();
}

void writeToFile(const std::string path, std::string& data)
{
  std::ofstream output;
  output.open(path);

  if (!output.is_open())
  {
    throw std::exception("Неверно указан файл для выходных данных. возможно указанного расположения не существует или нет прав на запись.");
  }
  else
  {
    output << data;
  }
  output.close();
}

std::string checkNumber(const std::string& roman)
{
  if (roman.size() > 15) // MMMDC CCLXX XVIII - 3888
    return "Длина числа не может быть больше 15 символов.";

  std::map <char, int> dictionary =
  { {'I', 1}, {'V' ,5}, {'X', 10}, {'L', 50}, {'C' ,100}, {'D', 500}, {'M', 1000} };

  for (size_t i{}; i < roman.size(); ++i)
  {
    if (!dictionary[roman[i]])
    {
      return ("Cимвол номер " + std::to_string(i + 1) + " неопознан");
    }
  }

  std::string romanNumber = "";
  for (size_t i = 0; i < roman.size(); ++i)
  {
    romanNumber.push_back(roman[i]);

    int decimalNumber = romanToInt(romanNumber);
    if (decimalNumber > 3999 || decimalNumber < 1)
    {
      return "Символ " + std::string(1, roman[i]) + ", номер " + std::to_string(i + 1) + " в строке, не может идти после " + roman.substr(0, i);
    }

    if (roman != intToRoman(decimalNumber))
    {
      return "Символ " + std::string(1, roman[i]) + ", номер " + std::to_string(i + 1) + " в строке, не может идти после " + roman.substr(0, i);
    }
  }
  return "";
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