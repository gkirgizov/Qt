#pragma once

template<class T>
class Stack
{
public:
	///
	/// \brief push
	/// Add data to the stack
	///
    virtual void push(T *data) = 0;

	///
	/// \brief pop
	/// Remove data from the stack
	///
    virtual T pop() = 0;

	///
	/// \brief top
	/// Get top item in the stack
	///
    virtual T top() = 0;

	///
	/// \brief getSize
	/// Returns number of items in the stack
	///
    virtual int getSize() = 0;

    virtual ~Stack(){}

private:
    int size;
};
