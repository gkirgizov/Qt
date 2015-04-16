#include <iostream>
#include <vector>
#include <string>
#include "stack.h"
#include "linkedstack.h"
#include "calcstack.h"

using namespace std;

///
/// \brief doOperation
/// Do operation 'key' with the operands 'first' and 'second'
///
int doOperation(char key, int first, int second)
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

///
/// \brief separator
/// Splits string to the tokens
///
vector<string> separator(string const &inputString)
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

bool isOperator(string const &token)
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

bool isNumber(string const &token)
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

int calculate(string const &inputString)
{
    Stack<int> *stack = new LinkedStack<int>();
    vector<string> tokens = separator(inputString);

    for(const string &token : tokens)
    {
        if (isOperator(token))
        {
			int second = stack->pop();
			int first = stack->pop();
			stack->push(new int (doOperation(token[0], first, second)));
        }
        else if (isNumber(token))
        {
			stack->push(new int (stoi(token)));
        }
    }
    int result = stack->top();
    delete stack;
    return result;
}
