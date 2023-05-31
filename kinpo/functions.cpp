/*!
*\file
*\brief ������  ���� �������� � ���� ���������� �������� �������, ������� ������������ � ���������.
*/

#include "functions.h"

int romanToInt(const std::string& roman)
{
  int ans{}; //���������� ��� ����������
  std::map <char, int> dictionary =
  { {'I', 1}, {'V' ,5}, {'X', 10}, {'L', 50}, {'C' ,100}, {'D', 500}, {'M', 1000} }; //������� ������� ����

  for (size_t i{}; i < roman.size(); ++i) //��� ������� ������� � ������ roman
  {
    if ((i + 1 < roman.size()) && (dictionary[roman[i]] < dictionary[roman[i + 1]])) //�������� �������� ������� ������ �������� ���������� ������� � ������� ������ �� �������� ���������
      ans -= dictionary[roman[i]]; //������� �������� �������� ������� �� ans
    else
      ans += dictionary[roman[i]]; //����� �������� �������� �������� ������� � ans
  }

  return ans;
}

std::string intToRoman(const int& number)
{
  std::vector<std::string> digits{ "", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX" }, // ������� ����� ��� ������
    tens{ "", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC" }, // ������� ����� ��� ��������
    hundreds{ "", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM" }, // ������� ����� �����
    thousands{ "", "M", "MM", "MMM" }; // ������� ����� ��� �����

  return thousands[number / 1000] + hundreds[(number % 1000) / 100] //������� ������������ ���� ������� ����
    + tens[(number % 100) / 10] + digits[number % 10];
}

void splitFraction(std::string romanString, std::string& romanNumerator, std::string& romanDenominator)
{
  if (!romanString.size()) //��������� ������� ������� ������
    throw std::runtime_error("����������� ������� ������.");

  size_t slashIndex = romanString.find('/'); //��������� ������� ������� �����������
  if (slashIndex == std::string::npos)
    throw std::runtime_error("����������� ������ �����������. ������� ���������, ������ ����������� \"/\", �����������, �� �������� �� ���������.");

  romanNumerator = romanString.substr(0, slashIndex); //��������� ��������� �����
  if (!romanNumerator.size()) //��������� ������� ���������
    throw std::runtime_error("����������� ��������� �����. ������� ���������, ������ ����������� \"/\", �����������, �� �������� �� ���������."); \

    romanDenominator = romanString.substr(slashIndex + 1); //��������� ����������� �����
  if (!romanDenominator.size()) //��������� ������� �����������
    throw std::runtime_error("����������� ����������� �����. ������� ���������, ������ ����������� \"/\", �����������, �� �������� �� ���������.");

  return;
}

std::string checkNumber(const std::string& roman)
{
  if (roman.size() > 15) //��������� ������������ �����
    return "����� ����� �� ����� ���� ������ 15 ��������.";

  std::map <char, int> dictionary =
  { {'I', 1}, {'V' ,5}, {'X', 10}, {'L', 50}, {'C' ,100}, {'D', 500}, {'M', 1000} }; //������� ������� ����

  for (size_t i{}; i < roman.size(); ++i) //��������� ������ ������ �� ��� ����������� � �������
  {
    if (!dictionary[roman[i]])
    {
      return ("C����� ����� " + std::to_string(i + 1) + " ���������.");
    }
  }

  std::string romanNumber = ""; //���������� �������� �����
  for (size_t i = 0; i < roman.size(); ++i) //��� ������� ������� �������� �����;
  {
    romanNumber.push_back(roman[i]); //�������� ������ � ���������� romanNumber;

    int decimalNumber = romanToInt(romanNumber); //��������� romanNumber � ���������� �����;
    if (decimalNumber > 3999 || decimalNumber < 1) //��������� ������������ ��������
    {
      return "������ " + std::string(1, roman[i]) + ", ����� " + std::to_string(i + 1) + " � ������, �� ����� ���� ����� " + roman.substr(0, i);
    }

    if (romanNumber != intToRoman(decimalNumber)) //��������� ������������ ��������� ����� � ������ ���������
    {
      return "������ " + std::string(1, roman[i]) + ", ����� " + std::to_string(i + 1) + " � ������, �� ����� ���� ����� " + roman.substr(0, i);
    }
  }
  return ""; //������� ������ ������, ��� ��� ������ �� �������.
}

std::string reduceFraction(std::string& romanNumerator, std::string& romanDenominator)
{
  // ��������� ������� ����� � ����������
  int numerator = romanToInt(romanNumerator);
  int denominator = romanToInt(romanDenominator);

  // ������� ��� � ��������� �����
  int divisor = std::gcd(numerator, denominator);
  numerator /= divisor;
  denominator /= divisor;

  // ��������� ����� � ������� ������� ���������
  romanNumerator = intToRoman(numerator);
  romanDenominator = intToRoman(denominator);

  // ������ ����� �����
  if (romanDenominator == "I")
    return romanNumerator;
  return romanNumerator + "/" + (romanDenominator);
}