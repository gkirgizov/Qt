#pragma once
#include "stack.h"

template<class T>
class LinkedStack : public Stack<T>
{
public:
    LinkedStack() //: size(0), head(nullptr)
    {
        this->size = 0;
        this->head = nullptr;
    }

    void push(T *data)
    {
        this->head = new Item(data, this->head);
        ++this->size;
    }

    T pop()
    {
        Item *ptr = this->head;
        this->head = this->head->prev;
        --this->size;

        T returned = *ptr->data;
        delete ptr;
        return returned;
    }

    T top()
    {
        return *this->head->data;
    }

    int getSize()
    {
        return this->size;
    }

    ~LinkedStack()
    {
		while (this->head != nullptr)
        {
			this->pop();
        }
    }


private:
    class Item
    {
    public:
        Item(T *data, Item *prev = nullptr)
        {
            this->data = data;
            this->prev = prev;
        }

        T *data;

        Item *prev;

        ~Item()
        {
            delete this->data;
        }
    };

    Item *head;

    int size;
};
