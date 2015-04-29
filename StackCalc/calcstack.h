#pragma once

#include <string>
#include <vector>

class CalcStack
{
public:
	///
	/// \brief calculate
	/// Calculates the equation inputted in the 'inputString'
	///
	static int calculate(std::string const &inputString);

	///
	/// \brief separator
	/// Splits string to the tokens
	///
	static std::vector<std::string> separate(std::string const &inputString);

private:
	///
	/// \brief doOperation
	/// Do operation 'key' with the operands 'first' and 'second'
	///
	static int doOperation(char key, int first, int second);

	static bool isOperator(std::string const &token);

	static bool isNumber(std::string const &token);
};
