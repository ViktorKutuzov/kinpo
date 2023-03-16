#include <iostream>
#include <string>
#include <map>
#include <fstream>
#include "functions.h"

int main (int argc, char* argv[])
{
    std::string roman = {};

    std::ifstream input;
    std::ofstream output;
    input.open(argv[1]);
    output.open(argv[2]);

    if (!output.is_open())
    {
        std::cout << "Output Error";
        return 0;
    }
    if (!input.is_open())
    {
        output << "Input Error";
    }
    else
    {
        std::getline(input, roman);
    }
    input.close();
    std::string romanNumerator = {};
    std::string romanDenominator = {};
    splitRoman(roman, romanNumerator, romanDenominator);
    auto numerator = romanToInt(romanNumerator);
    auto denominator = romanToInt(romanDenominator);
    reduceFraction(&numerator, &denominator);
    romanNumerator = intToRoman(numerator);
    romanDenominator = intToRoman(denominator);
    roman = createFraction(romanNumerator, romanDenominator);
    output << roman;
    output.close();
	return 0;
}

int romanToInt(std::string roman)
{
    int ans = 0;
    std::map <char, int> dictionary =
    { {'I', 1}, {'V' ,5}, {'X', 10}, {'L', 50}, {'C' ,100}, {'D', 500}, {'M', 1000} };

    for (int i = 0; i < roman.size(); ++i)
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
    std::string numbers[10] = { "","I","II","III","IV","V","VI","VII","VIII","IX" };
    std::string tens[10] = { "","X","XX","XXX","XL","L","LX","LXX","LXXX","XC" };
    std::string hundreds[10] = { "","C","CC","CCC","CD","D","DC","DCC","DCCC","CM" };
    std::string thousands[4] = { "","M","MM","MMM" };
    return thousands[number / 1000] + hundreds[(number % 1000) / 100] + tens[(number % 100) / 10] + numbers[number % 10];
}

int gcd(int a, int b)
{
    return !b ? a : gcd(b, a % b);
}

void reduceFraction(int* numerator, int* denominator)
{
    int divisor = gcd(*numerator, *denominator);
    *numerator /= divisor;
    *denominator /= divisor;
    return;
}

std::string createFraction(std::string romanNumerator, std::string romanDenominator)
{
    std::string test = "";
    return test.append(romanNumerator).append("/").append(romanDenominator);
}

void splitRoman(std::string romanString, std::string& romanNumerator, std::string& romanDenominator)
{
    int slashIndex = romanString.find('/');
    romanNumerator = romanString.substr(0, slashIndex);
    romanDenominator = romanString.substr(++slashIndex);
    return;
}