#pragma once

template<class T>
class IStack
{
public:
	IStack() :
		size_(0) {}

	virtual ~IStack() {}

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
	virtual T top() const = 0;

	///
	/// \brief size
	/// Returns number of items in the stack
	///
	int size() const
	{
		return size_;
	}

protected:
	int size_;
};
