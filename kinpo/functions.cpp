/*!
*\file
*\brief ������  ���� �������� � ���� ���������� �������� �������, ������� ������������ � ���������.
*/

#include "functions.h"

uint16_t romanToInt(const std::string& roman)
{
  uint16_t ans{}; //���������� ��� ����������
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

std::string intToRoman(uint16_t number)
{
  std::string digits[10] { "", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX" }, // ������� ����� ��� ������
    tens[10] { "", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC" }, // ������� ����� ��� ��������
    hundreds[10] { "", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM" }, // ������� ����� �����
    thousands[4] { "", "M", "MM", "MMM" }; // ������� ����� ��� �����

  std::string result;
  result.reserve(15); // �������������� ������������ ������ �������� ������

  result += thousands[number / 1000];
  result += hundreds[(number % 1000) / 100];
  result += tens[(number % 100) / 10];
  result += digits[number % 10];

  return result; //������� ������������ ���� ������� ����
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

    uint16_t decimalNumber = romanToInt(romanNumber); //��������� romanNumber � ���������� �����;
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
  uint16_t numerator = romanToInt(romanNumerator);
  uint16_t denominator = romanToInt(romanDenominator);

  // ������� ��� � ��������� �����
  uint16_t divisor = std::gcd(numerator, denominator);
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