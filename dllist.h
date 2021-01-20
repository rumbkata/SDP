#ifndef _DLLIST_H
#define _DLLIST_H

#include<iostream>

template <class T>
class DLList
{
private:
    struct box
    {
        T data;
        box *previous, *next;
    };
    box first;

public:
    class Iterator
    {
    private:
        box *first, *current;
        Iterator(box*, box*);
    public:
        T& operator*();
        Iterator& operator++();
        Iterator& operator--();
        bool operator!=(const Iterator&) const;
        

    };
    Iterator begin();
    Iterator last();
    Iterator end();
    DLList();
    DLList(const DLList<T>&);
    ~DLList();
    DLList<T>& operator= (const DLList<T>&);
    DLList<T> operator+ (const T&) const;
    DLList<T>& operator+= (const T&);
    //friend operator << (new template)!!!
private:
    void copy(const DLList<T>&);
    void clear();
};
template <class T>
std::ostream& operator<< (dst::ostream&, const DLList<T>&);

//include dllist.h
#endif 