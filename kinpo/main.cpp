#include "functions.h"

int main (int argc, char* argv[])
{
  //accelerator
  std::ios::sync_with_stdio(0);
  std::cin.tie(0);
  std::cout.tie(0);
  setlocale(LC_CTYPE, "Russian");


  std::string r;
  std::cin >> r;
  std::vector<std::string> er;

  for (const auto& i : er)
  {
    std::cout << i << std::endl;
  }
  if (er.size() == 0)
  {
    std::cout << "No errors found" << std::endl;
  }

  std::cout << "========END OF TEST========" << std::endl;

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

    std::string romanNumerator = {};
    std::string romanDenominator = {};

    splitFraction(roman, romanNumerator, romanDenominator);

    std::string result = reduceFraction(roman);

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
  // MMMDC CCLXX XVIII - 3888
  std::map <char, int> dictionary =
  { {'I', 1}, {'V' ,5}, {'X', 10}, {'L', 50}, {'C' ,100}, {'D', 500}, {'M', 1000} };
  bool error = false;

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

  std::string digits[10] {"","I","II","III","IV","V","VI","VII","VIII","IX"},
  tens[10]               {"","X","XX","XXX","XL","L","LX","LXX","LXXX","XC"},
  hundreds[10]           {"","C","CC","CCC","CD","D","DC","DCC","DCCC","CM"},
  thousands[4]           {"","M","MM","MMM"};

  return thousands[number / 1000] + hundreds[(number % 1000) / 100]
    + tens[(number % 100) / 10] + digits[number % 10];
}

void splitFraction(std::string romanString, std::string& romanNumerator, std::string& romanDenominator)
{
  if (!romanString.size())
    throw std::exception("����������� ������� ������.");
  size_t slashIndex = romanString.find('/');
  if (slashIndex == std::string::npos)
    throw std::exception("����������� ������ �����������. ������� ���������, ������ ����������� \"/\", �����������, �� �������� �� ���������.");
  romanNumerator = romanString.substr(0, slashIndex);
  if (!romanNumerator.size())
    throw std::exception("����������� ��������� �����. ������� ���������, ������ ����������� \"/\", �����������, �� �������� �� ���������.");
  romanDenominator = romanString.substr(slashIndex + 1);
  if (!romanDenominator.size())
    throw std::exception("����������� ����������� �����. ������� ���������, ������ ����������� \"/\", �����������, �� �������� �� ���������.");
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

  std::vector<std::string> numeratorErrors, denominatorErrors;
  bool error = false;

  int numerator = romanToInt(romanNumerator);
  if (numeratorErrors.size())
  {
    error = true;
    std::cout << "����������� ����� �������� ��������� ������ � ������:" << std::endl;
    for (const auto& i : numeratorErrors)
      std::cout << i << std::endl;
    std::cout << std::endl;
  }

  int denominator = romanToInt(romanDenominator);
  if (denominatorErrors.size())
  {
    error = true;
    std::cout << "��������� ����� �������� ��������� ������ � ������:" << std::endl;
    for (const auto& i : denominatorErrors)
      std::cout << i << std::endl;
  }
  if (error)
    throw std::exception(" ");


  int divisor = std::gcd(numerator, denominator);
  numerator /= divisor;
  denominator /= divisor;

  romanNumerator = intToRoman(numerator);
  romanDenominator = intToRoman(denominator);

  if (romanDenominator == "I")
    return romanNumerator;
  return romanNumerator + "/" + (romanDenominator);
}

std::string checkNumber(const std::string roman)
{
  if (roman.size() > 15)
    return "����� ����� �� ����� ���� ������ 15 ��������.";

  std::map <char, int> dictionary =
  { {'I', 1}, {'V' ,5}, {'X', 10}, {'L', 50}, {'C' ,100}, {'D', 500}, {'M', 1000} };

  for (size_t i{}; i < roman.size(); ++i)
  {
    if (!dictionary[roman[i]])
    {
      return ("C����� ����� " + std::to_string(i + 1) + " ���������");
    }
  }

  std::string romanNumber = "";
  for (size_t i = 0; i < roman.size(); ++i)
  {
    romanNumber.push_back(roman[i]);

    int decimalNumber = romanToInt(romanNumber);
    if (decimalNumber > 3999 || decimalNumber < 1)
    {
      return "������ " + std::string(1, roman[i]) + ", ����� " + std::to_string(i + 1) + " � ������, �� ����� ���� ����� " + roman.substr(0, i);
    }

    if (roman != intToRoman(decimalNumber))
    {
      return "������ " + std::string(1, roman[i]) + ", ����� " + std::to_string(i + 1) + " � ������, �� ����� ���� ����� " + roman.substr(0, i);
    }
  }
  return "";
}