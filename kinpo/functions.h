#pragma once

/*!
	\param[in]
	\param[in]
	\param[in]
	\return
*/
int romanToInt(std::string roman);

/*!
	\param[in]
	\param[in]
	\param[in]
	\return
*/
std::string intToRoman(int number);

/*!
	\param[in]
	\param[in]
	\param[in]
	\return
*/
void reduceFraction(int* numerator, int* denominator);

/*!
	\param[in]
	\param[in]
	\param[in]
	\return
*/
std::string createFraction(std::string romanNumerator, std::string romanDenominator);

/*!
	\param[in]
	\param[in]
	\param[in]
	\return
*/
void splitRoman(std::string romanString, std::string& romanNumerator, std::string& romanDenominator);