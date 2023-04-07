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

  try
  {
    //if (argv[1] == NULL || argv[2] == NULL) 
    //{
    //    throw std::exception("�� ������� ������������ ������ � �������� � ��������� �������.");
    //}

    std::string inpath = "input.txt";
    std::string outpath = "output.txt";

    readFile(inpath, roman);

    std::string result = reduceFraction(roman);

    writeToFile(outpath, result);
    return 0;
  }

  catch (const std::exception& ex)
  {
    std::cout << ex.what() << std::endl;
  }
}

int romanToInt(const std::string& roman)
{
  int ans = 0;
  std::map <char, int> dictionary =
  { {'I', 1}, {'V' ,5}, {'X', 10}, {'L', 50}, {'C' ,100}, {'D', 500}, {'M', 1000} };

  for (size_t i = 0; i < roman.size(); ++i)
  {
    if (!dictionary[roman[i]])
      throw std::exception("������������ ������");
    if (dictionary[roman[i]] < dictionary[roman[i + 1]] && i < roman.size() - 1)  
      ans -= dictionary[roman[i]];
    else
      ans += dictionary[roman[i]];
  }
  if (roman != intToRoman(ans))
    throw std::exception("������������ ������ �����");
  return ans;
}

std::string intToRoman(const int& number)
{
  std::string digits[10] = { "","I","II","III","IV","V","VI","VII","VIII","IX" },
  tens[10]               = { "","X","XX","XXX","XL","L","LX","LXX","LXXX","XC" },
  hundreds[10]           = { "","C","CC","CCC","CD","D","DC","DCC","DCCC","CM"},
  thousands[4]           = { "","M","MM","MMM" };
  return thousands[number / 1000] + hundreds[(number % 1000) / 100] + tens[(number % 100) / 10] + digits[number % 10];
}

std::string createFraction(const std::string& romanNumerator, const std::string& romanDenominator)
{
  if (romanDenominator == "I")
    return romanNumerator;
  return romanNumerator + "/" + (romanDenominator);
}

void splitFraction(std::string romanString, std::string& romanNumerator, std::string& romanDenominator)
{
  if (!romanString.size())
    throw std::exception("��� ������� ������");
  size_t slashIndex = romanString.find('/');
  if (slashIndex == std::string::npos)
    throw std::exception("����������� ������ �����������. ������� ���������, ������ ����������� \"/\", �����������, �� �������� �� ���������");
  romanNumerator = romanString.substr(0, slashIndex);
  if (!romanNumerator.size())
    throw std::exception("����������� ��������� �����. ������� ���������, ������ ����������� \"/\", �����������, �� �������� �� ���������");
  romanDenominator = romanString.substr(slashIndex + 1);
  if (!romanDenominator.size())
    throw std::exception("����������� ����������� �����. ������� ���������, ������ ����������� \"/\", �����������, �� �������� �� ���������");
  return;
}

void readFile(const std::string path, std::string& data)
{
  std::ifstream input;
  input.open(path);
  if (!input.is_open())
  {
    throw std::exception("������� ������ ���� � �������� �������. ��������, ���� �� ����������.");
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
    throw std::exception("������� ������ ���� ��� �������� ������. �������� ���������� ������������ �� ���������� ��� ��� ���� �� ������.");
  }
  else
  {
    output << data;
  }
  output.close();
}

std::string reduceFraction(const std::string& roman)
{
  std::string romanNumerator = {};
  std::string romanDenominator = {};

  splitFraction(roman, romanNumerator, romanDenominator);

  int numerator = romanToInt(romanNumerator);
  int denominator = romanToInt(romanDenominator);

  int divisor = std::gcd(numerator, denominator);
  numerator /= divisor;
  denominator /= divisor;

  romanNumerator = intToRoman(numerator);
  romanDenominator = intToRoman(denominator);

  std::string result = createFraction(romanNumerator, romanDenominator);
  return result;
}
//int gcd(int a, int b){ return !b ? a : gcd(b, a % b);} ���� ������� gcd �� ��������� �������