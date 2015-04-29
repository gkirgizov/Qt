#pragma once

#include "istack.h"

template<class T>
class LinkedStack : public IStack<T>
{
public:
	LinkedStack() :
		size_(0),
		head(nullptr) {}

	~LinkedStack()
	{
		while (this->head != nullptr)
		{
			this->pop();
		}
	}

	void push(T data)
    {
        this->head = new Item(data, this->head);
		++this->size_;
    }

    T pop()
    {
        Item *ptr = this->head;
        this->head = this->head->prev;
		--this->size_;

		T returned = ptr->data;
        delete ptr;
        return returned;
    }

    T top()
    {
		return this->head->data;
    }

	int size()
    {
		return this->size_;
    }

private:
    class Item
    {
    public:
		Item(T data, Item *prev = nullptr) :
			data(data),
			prev(prev) {}

		T data;
        Item *prev;
    };

    Item *head;
	int size_;
};
