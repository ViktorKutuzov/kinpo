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
    //    throw std::exception("Не указаны расположения файлов с входными и выходными данными.");
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
  catch (...)
  {

  }
}

void findError(const std::string& roman, std::vector<std::string>& errors) 
{

  return;
}

int romanToInt(const std::string& roman, std::vector<std::string>& errors)
{
  int ans{};
  // MMMDCCCLXXXVIII - 3888
  std::map <char, int> dictionary =
  { {'I', 1}, {'V' ,5}, {'X', 10}, {'L', 50}, {'C' ,100}, {'D', 500}, {'M', 1000} };
  bool error = false;

  if (roman.size() > 15)
  {
    errors.push_back("Римское число не может быть длиннее 15 символов.");
    return 0;
  }
  for (size_t i{}; i < roman.size(); ++i)
  {
    if (!dictionary[roman[i]])
    {
      error = true;
      errors.push_back("Cимвол номер " + std::to_string(i + 1) + " неопознан.");
    }
  }

  if (error)
    return 0;

  for (size_t i{}; i < roman.size(); ++i)
  {
    if (dictionary[roman[i]] < dictionary[roman[i + 1]] && i < roman.size() - 1)  
      ans -= dictionary[roman[i]];
    else
      ans += dictionary[roman[i]];
  }

  if (ans <= 0)
  {
    errors.push_back("Римское число не может меньше 1.");
    return 0;
  }
  if (ans > 3999)
  {
    errors.push_back("Римское число не может больше 3999.");
    return 0;
  }

  if (roman != intToRoman(ans))
    errors.push_back("Римское число имеет неверный формат. Возможно, вы имели в виду число " + intToRoman(ans) + " ?");
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
    throw std::exception("Отсутствуют входные данные.");
  size_t slashIndex = romanString.find('/');
  if (slashIndex == std::string::npos)
    throw std::exception("Отсутствует символ разделителя. Введите числитель, символ разделителя \"/\", знаменатель, не разделяя их пробелами.");
  romanNumerator = romanString.substr(0, slashIndex);
  if (!romanNumerator.size())
    throw std::exception("Отсутствует числитель дроби. Введите числитель, символ разделителя \"/\", знаменатель, не разделяя их пробелами.");
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

std::string reduceFraction(const std::string& roman)
{
  std::string romanNumerator = {};
  std::string romanDenominator = {};

  splitFraction(roman, romanNumerator, romanDenominator);

  std::vector<std::string> numeratorErrors, denominatorErrors;
  bool error = false;

  int numerator = romanToInt(romanNumerator, numeratorErrors);
  if (numeratorErrors.size())
  {
    error = true;
    std::cout << "Знаменатель дроби содержит следующие ошибки в записи:" << std::endl;
    for (const auto& i : numeratorErrors)
      std::cout << i << std::endl;
    std::cout << std::endl;
  }

  int denominator = romanToInt(romanDenominator, denominatorErrors);
  if (denominatorErrors.size())
  {
    error = true;
    std::cout << "Числитель дроби содержит следующие ошибки в записи:" << std::endl;
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