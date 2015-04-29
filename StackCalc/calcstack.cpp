#include <iostream>
#include <vector>
#include <string>

#include "istack.h"
#include "linkedstack.h"
#include "calcstack.h"

using namespace std;

int CalcStack::calculate(string const &inputString)
{
	IStack<int> *stack = new LinkedStack<int>();
	vector<string> tokens = separate(inputString);

    for(const string &token : tokens)
    {
		if (isOperator(token))
        {
			int second = stack->pop();
			int first = stack->pop();
			stack->push(doOperation(token[0], first, second));
        }
        else if (isNumber(token))
        {
			stack->push(stoi(token));
        }
    }
    int result = stack->top();
    delete stack;
    return result;
}

vector<string> CalcStack::separate(string const &inputString)
{
	vector<string> tokens;
	int begin = 0;
	for (unsigned int end = 0; end < inputString.size(); ++end)
	{
		if (inputString[end] == ' ')
		{
			int length = end - begin;
			if (length != 0)
			{
				tokens.push_back(inputString.substr(begin, length));
				begin = end + 1;
			}
		}
	}
	string lastToken = inputString.substr(begin);
	if (lastToken != "")
	{
		tokens.push_back(lastToken);
	}
	return tokens;
}

int CalcStack::doOperation(char key, int first, int second)
{
	if (key == '+')
	{
		return first + second;
	}
	else if (key == '-')
	{
		return first - second;
	}
	else if (key == '*')
	{
		return first * second;
	}
	else if (key == '/')
	{
		return first / second;
	}
	return 0;
}

bool CalcStack::isOperator(string const &token)
{
	if (token.size() == 1)
	{
		return (token[0] == '+' ||
			token[0] == '-' ||
			token[0] == '*' ||
			token[0] == '/');
	}
	return false;
}

bool CalcStack::isNumber(string const &token)
{
	for (unsigned int i = 0; i < token.size(); ++i)
	{
		if (!(token[i] >= '0' && token[i] <= '9'))
		{
			return false;
		}
	}
	return true;
}
