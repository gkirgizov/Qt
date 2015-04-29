#pragma once

template<class T>
class IStack
{
public:
	///
	/// \brief push
	/// Add data to the stack
	///
	virtual void push(T data) = 0;

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
	/// \brief size
	/// Returns number of items in the stack
	///
	virtual int size() = 0;

private:
	int size_;
};
