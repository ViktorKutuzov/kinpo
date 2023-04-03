#include <iostream>
#include <string>
#include <map>
#include <fstream>
#include <numeric>
#include "functions.h"


int main (int argc, char* argv[])
{
  //accelerator
  std::ios::sync_with_stdio(0);
  std::cin.tie(0);
  std::cout.tie(0);
  setlocale(LC_CTYPE, "Russian");

  std::string roman = {};
  std::ifstream input;
  std::ofstream output;

  try
  {
    //if (argv[1] == NULL || argv[2] == NULL) 
    //{
    //    throw std::exception("Не указаны расположения файлов с входными и выходными данными.");
    //}
    //input.open(argv[1]);
    //output.open(argv[2]);
    //readFile(argv[1], roman);
    input.open("input.txt");
    output.open("output.txt");

    if (!output.is_open())
    {
      throw std::exception("Неверно указан файл для выходных данных. Возможно указанного расположения не существует или нет прав на запись.");
    }
    if (!input.is_open())
    {
      throw std::exception("Неверно указан файл с входными данными. Возможно, файл не существует.");
    }
    else
    {
      input >> roman;
      //std::getline(input, roman);
    }
    input.close();

    std::string romanNumerator = {};
    std::string romanDenominator = {};

    splitRoman(roman, romanNumerator, romanDenominator);

    auto numerator = romanToInt(romanNumerator);
    auto denominator = romanToInt(romanDenominator);

    reduceFraction(numerator, denominator);

    romanNumerator = intToRoman(numerator);
    romanDenominator = intToRoman(denominator);

    roman = createFraction(romanNumerator, romanDenominator);

    output << roman;

    output.close();
    return 0;
  }

  catch (const std::exception& ex)
  {
    std::cout << ex.what() << std::endl;
  }
}

int romanToInt(std::string roman)
{
  int ans = 0;
  std::map <char, int> dictionary =
  { {'I', 1}, {'V' ,5}, {'X', 10}, {'L', 50}, {'C' ,100}, {'D', 500}, {'M', 1000} };

  for (size_t i = 0; i < roman.size(); ++i)
  {
    if (dictionary[roman[i]] < dictionary[roman[i + 1]]) 
      ans -= dictionary[roman[i]];
    else
      ans += dictionary[roman[i]];
  }
  return ans;
}

std::string intToRoman(int number)
{
  std::string digits[10] = { "","I","II","III","IV","V","VI","VII","VIII","IX" },
  tens[10]               = { "","X","XX","XXX","XL","L","LX","LXX","LXXX","XC" },
  hundreds[10]           = { "","C","CC","CCC","CD","D","DC","DCC","DCCC","CM"},
  thousands[4]           = { "","M","MM","MMM" };
  return thousands[number / 1000] + hundreds[(number % 1000) / 100] + tens[(number % 100) / 10] + digits[number % 10];
}


//int gcd(int a, int b){ return !b ? a : gcd(b, a % b);}

void reduceFraction(int& numerator, int& denominator)
{
  int divisor = std::gcd(numerator, denominator);
  numerator /= divisor;
  denominator /= divisor;
  return;
}

std::string createFraction(std::string romanNumerator, std::string romanDenominator)
{
  if (romanDenominator == "I")
    return romanNumerator;
  return romanNumerator + "/" + (romanDenominator);
}

void splitRoman(std::string romanString, std::string& romanNumerator, std::string& romanDenominator)
{
  if (!romanString.size())
    throw std::exception("Нет входных данных");
  size_t slashIndex = romanString.find('/');
  if (slashIndex == std::string::npos)
    throw std::exception("Отсутствует символ разделителя. Введите числитель, символ разделителя \"/\", знаменатель, не разделяя их пробелами");
  romanNumerator = romanString.substr(0, slashIndex);
  if (!romanNumerator.size())
    throw std::exception("Отсутствует числитель дроби. Введите числитель, символ разделителя \"/\", знаменатель, не разделяя их пробелами");
  romanDenominator = romanString.substr(slashIndex + 1);
  if (!romanDenominator.size())
    throw std::exception("Отсутствует знаменатель дроби. Введите числитель, символ разделителя \"/\", знаменатель, не разделяя их пробелами");
  return;
}

void readFile(std::string path, std::string& data)
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

void writeToFile(std::string path, std::string& data)
{
  std::ofstream output;
  output.open(path);

  if (!output.is_open())
  {
    throw std::exception("Неверно указан файл для выходных данных. Возможно указанного расположения не существует или нет прав на запись.");
  }
  else
  {
    output << data;
  }
  output.close();
}