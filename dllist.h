#ifndef _DLLIST_H
#define _DLLIST_H

template <class T>
class DLList
{
private:
    box first;
    struct box
    {
        T data;
        box *next, *previous;
    };
public:
    DLList();
    DLList(const DLList<T>&);
    ~DLList();
    DLList<T>& operator= (const DLList<T>&);
};

#endif 