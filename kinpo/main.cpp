/*!
*\file
*\brief Данный файл содержит главную управляющую функцию программы
*\mainpage Документация для программы "FractionReducer"
Программа предназначена для сокращения дроби, записанной в римской системе счисления.
Для функционирования программы необходима операционная система Windows 10 или выше.
Программа разработана на языке С++ с использованием библиотеки STL в IDE Microsoft Visual Studio 2022.
Стандарт языка ISO C++17 (/std:c++17).
Программа должна получать два параметра командной строки: имя входного файла с записанной в римской системе счисления дробью.

Пример команды запуска программы:
*\code
FractionReducer.exe C:\\Documents\input.txt C:\\Documents\output.txt
*\endcode
*\author Viktor Kutuzov
*\date Май 2023 года
*\version 1.0
*/

#include "functions.h"


/*!
*\brief Главная управляющая функция программы
*\param[in] char* argv[0]- путь к программе
*\param[in] char* argv[1] - путь к входному файлу с данными
*\param[in] char* argv[2] - путь к выходному файлу для записи
*\return 0, если программа завершилась корректно
*/
int main (int argc, char* argv[])
{
  setlocale(LC_ALL, "Russian"); // Русская локализация консоли
  try
  {
    if (argv[1] == NULL || argv[2] == NULL) 
    {
        throw std::runtime_error("Недостаточно параметров для запуска программы.");
    }

    int q = 100000;
    while (q--)
    {
      std::string roman{}; //Переменная для римской дроби

      // Считываем данные из входного файла
      std::ifstream input;
      input.open(argv[1]);
      if (!input.is_open())
        throw std::runtime_error("Неверно указан файл с входными данными. Возможно, файл не существует.");
      else
        input >> roman;
      input.close();

      // Переменные для числителя и знаменателя
      std::string romanNumerator{};
      std::string romanDenominator{};

      // Разделяем дробь на числитель и знаменатель
      splitFraction(roman, romanNumerator, romanDenominator);

      // Проверяем числитель на корректность
      std::string error = checkNumber(romanNumerator);
      if (!error.empty())
      {
        throw std::runtime_error("Числитель содержит ошибку в записи. " + error);
      }

      // Проверяем знаменатель на корректность
      error = checkNumber(romanDenominator);
      if (!error.empty())
      {
        throw std::runtime_error("Знаменатель содержит ошибку в записи. " + error);
      }

      // Сокращаем дробь
      roman = reduceFraction(romanNumerator, romanDenominator);

      // Записываем данные в выходной файл
      std::ofstream output;
      output.open(argv[2]);
      if (!output.is_open())
        throw std::runtime_error("Неверно указан файл для выходных данных. Возможно указанного расположения не существует или нет прав на запись.");
      else
        output << roman;
      output.close();
    }

  }

  catch (const std::runtime_error& ex)
  {
    std::cout << ex.what() << std::endl;
  }
}