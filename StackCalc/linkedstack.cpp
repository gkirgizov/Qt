#include "linkedstack.h"


template<class T>
LinkedStack<T>::LinkedStack() : size(0), head(nullptr)
{
}

template<class T>
LinkedStack<T>::Item::Item(T data, Item *prev)
{
    this->data = data;
    this->prev = prev;
}

template<class T>
LinkedStack<T>::Item::~Item()
{
    delete this->data;
    delete this->prev;
}

template<class T>
void LinkedStack<T>::push(T data)
{
    //хитрый конструктор Item позволяет сразу перекидывать указатели
    this->head = new Item(data, this->head);
    ++this->size;
}

template<class T>
T LinkedStack<T>::pop()
{
    T *ptr = this->head;
    this->head = this->head->prev;
    --this->size;

    T returned = ptr->data;
    delete ptr;
    return returned;
}

template<class T>
T LinkedStack<T>::top()
{
    return this->head->data;
}

template<class T>
int LinkedStack<T>::getSize()
{
    return this->size;
}

template<class T>
LinkedStack<T>::~LinkedStack()
{
    if (this->head != nullptr)
    {
        delete this->head;
    }
}
