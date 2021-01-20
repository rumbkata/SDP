template <class T>
DLList<T>::DLList()
{
    first.next = &first;
    first.previous = &first;
}

template <class T>
DLList<T>::DLList(const DLList<T>& source)
{
    copy(source);
}

template <class T>
DLList<T>::~DLList()
{
    clear();
}

template <class T>
DLList<T>::DLList<T> &operator=(const DLList<T>& sample)
{
    clear();
    copy(sample);
}

template <class T>
DLList<T>::DLList<T> operator+(const T &) const
{

}

template <class T>
DLList<T>::DLList<T>& operator+=(const T& data)
{
    bool flag = this->empty();
    first.next = new DLList<T>::box {data, &first, first.next};
    //first.next->next->previous = first.next;
    if(flag)
        first.previous = first.next;
    return *this;
}

template <class T>
DLList<T>::template <class T
{

}

std::ostream &operator<<(dst::ostream &, const DLList<T> &)
{

}