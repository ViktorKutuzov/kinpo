/*!
*\file
*\brief ������ ���� �������� ������� ����������� ������� ���������
*\mainpage ������������ ��� ��������� "FractionReducer"
��������� ������������� ��� ���������� �����, ���������� � ������� ������� ���������.
��� ���������������� ��������� ���������� ������������ ������� Windows 10 ��� ����.
��������� ����������� �� ����� �++ � �������������� ���������� STL � IDE Microsoft Visual Studio 2022.
�������� ����� ISO C++17 (/std:c++17).
��������� ������ �������� ��� ��������� ��������� ������: ��� �������� ����� � ���������� � ������� ������� ��������� ������.

������ ������� ������� ���������:
*\code
FractionReducer.exe C:\\Documents\input.txt C:\\Documents\output.txt
*\endcode
*\author Viktor Kutuzov
*\date ��� 2023 ����
*\version 1.0
*/

#include "functions.h"


/*!
*\brief ������� ����������� ������� ���������
*\param[in] char* argv[0]- ���� � ���������
*\param[in] char* argv[1] - ���� � �������� ����� � �������
*\param[in] char* argv[2] - ���� � ��������� ����� ��� ������
*\return 0, ���� ��������� ����������� ���������
*/
int main (int argc, char* argv[])
{
  setlocale(LC_ALL, "Russian"); // ������� ����������� �������
  try
  {
    if (argv[1] == NULL || argv[2] == NULL) 
    {
        throw std::runtime_error("������������ ���������� ��� ������� ���������.");
    }

    int q = 100000;
    while (q--)
    {
      std::string roman{}; //���������� ��� ������� �����

      // ��������� ������ �� �������� �����
      std::ifstream input;
      input.open(argv[1]);
      if (!input.is_open())
        throw std::runtime_error("������� ������ ���� � �������� �������. ��������, ���� �� ����������.");
      else
        input >> roman;
      input.close();

      // ���������� ��� ��������� � �����������
      std::string romanNumerator{};
      std::string romanDenominator{};

      // ��������� ����� �� ��������� � �����������
      splitFraction(roman, romanNumerator, romanDenominator);

      // ��������� ��������� �� ������������
      std::string error = checkNumber(romanNumerator);
      if (!error.empty())
      {
        throw std::runtime_error("��������� �������� ������ � ������. " + error);
      }

      // ��������� ����������� �� ������������
      error = checkNumber(romanDenominator);
      if (!error.empty())
      {
        throw std::runtime_error("����������� �������� ������ � ������. " + error);
      }

      // ��������� �����
      roman = reduceFraction(romanNumerator, romanDenominator);

      // ���������� ������ � �������� ����
      std::ofstream output;
      output.open(argv[2]);
      if (!output.is_open())
        throw std::runtime_error("������� ������ ���� ��� �������� ������. �������� ���������� ������������ �� ���������� ��� ��� ���� �� ������.");
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