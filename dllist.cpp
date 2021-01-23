#ifndef _DLLIST_CPP
#define _DLLIST_CPP

#include <iostream>
#include <exception>
#include "dllist.h"
//iterator
template <class T>
DLList<T>::Iterator::Iterator(box* _first, box* _current) : first(_first), current(_current)
{
}

template <class T>
T &DLList<T>::Iterator::operator*()
{
    if (current == first)
    {
        throw std::out_of_range("Nil iterator");
    }
    return current->data;
}

template <class T>
typename DLList<T>::Iterator &DLList<T>::Iterator::operator++()
{
    if (current == first)
    {
        throw std::out_of_range("Nil iterator");
    }
    current = current->next;
    return *this;
}

template <class T>
typename DLList<T>::Iterator &DLList<T>::Iterator::operator--()
{
    if (current == first)
    {
        throw std::out_of_range("Nil iterator");
    }
    current = current->previous;
    return *this;
}

template <class T>
bool DLList<T>::Iterator::operator!=(const Iterator &it) const
{
    return this->current != it.current;
}
//it
template <class T>
typename DLList<T>::Iterator DLList<T>::begin()
{
    return DLList<T>::Iterator(&first, first.next);
}

template <class T>
typename DLList<T>::Iterator DLList<T>::last()
{
    return DLList<T>::Iterator(&first, first.previous);
}

template <class T>
typename DLList<T>::Iterator DLList<T>::end()
{
    return DLList<T>::Iterator(&first, &first);
}
//list
template <class T>
DLList<T>::DLList()
{
    first.next = first.previous = &first;
}

template <class T>
DLList<T>::DLList(const DLList<T> &sample)
{
    this->copy(sample);
}

template <class T>
DLList<T>::~DLList()
{
    this->clear();
}

template <class T>
DLList<T> &DLList<T>::operator=(const DLList<T> &sample)
{
    if (this != sample)
    {
        this->clear();
        this->copy(sample);
    }
    return *this;
}

template <class T>
DLList<T> DLList<T>::operator+(const T &data) const
{
    DLList<T> list(*this);
    list += data;
    return list;
}

template <class T>
DLList<T> &DLList<T>::operator+=(const T &_data)
{
    first.next = new box{_data, &first, first.next};
    first.next->next->previous = first.next;
    return *this;
}

template <class T>
bool DLList<T>::empty() const
{
    return first.next == &first;
}

template <class T>
void DLList<T>::copy(const DLList<T> &sample)
{
    box *curr = sample.first.next;
    while (curr != &sample.first)
    {
        *this += curr->data;
        curr = curr->next;
    }
}

template <class T>
void DLList<T>::clear()
{
    box *helper, *curr = first.next;
    while (curr != &first)
    {
        helper = curr;
        curr = curr->next;
        delete helper;
    }
}

template <class T>
std::ostream& operator<<(std::ostream& out, DLList<T>& list)
{
    typename DLList<T>::Iterator it = list.begin();
    while (it != list.end())
    {
        out << *it << " ";
        ++it;
    }
    return out;
}

#endif