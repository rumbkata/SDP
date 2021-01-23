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
    public:
        Iterator(box*, box*);
        T& operator*();
        Iterator& operator++();
        Iterator& operator--(); //done
        bool operator!=(const Iterator&) const; //done
        

    };
    Iterator begin();
    Iterator last();
    Iterator end();
    //
    DLList(); //done
    DLList(const DLList<T>&); //done
    ~DLList(); //done
    //
    DLList<T>& operator= (const DLList<T>&); // done
    DLList<T> operator+ (const T&) const; //done
    DLList<T>& operator+= (const T&); //done
    //friend operator << (new template)!!!
    bool empty() const; //done
private:
    void copy(const DLList<T>&); //done
    void clear(); //done
};
template <class T>
std::ostream& operator<<(std::ostream&, DLList<T>&);


#include "dllist.cpp"

#endif 