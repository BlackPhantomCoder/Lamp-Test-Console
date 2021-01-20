#pragma once
//Positive direct Iterator based on ptr
template <class T, class size_type>
class PtrIterator {
public:
    PtrIterator(PtrIterator&&) = default;
    PtrIterator(const PtrIterator&) = default;

    PtrIterator(T* ptr, size_type pos) : t_ptr(ptr), t_pos(pos) {}
    ~PtrIterator() = default;

    PtrIterator& operator=(const PtrIterator&) = default;
    PtrIterator& operator=(PtrIterator&&) = default;

    PtrIterator& operator++();
    PtrIterator operator++(int);

    bool operator!=(const PtrIterator& rh)const;
    bool operator==(const PtrIterator& rh)const;

    T& operator*();
    T& operator->();

    const T& operator*()const;
    const T& operator->()const;
protected:
    T& t_get_val();
    const T& t_get_val()const;
private:
    //start_ptr
    T* t_ptr;
    //offset
    size_type t_pos;
};

//Positive direct ConstIterator based on ptr
template <class T, class size_type>
class ConstPtrIterator {
public:
    ConstPtrIterator(ConstPtrIterator&&) = default;
    ConstPtrIterator(const ConstPtrIterator&) = default;
    ConstPtrIterator(const T* ptr, size_type pos);
    ~ConstPtrIterator() = default;

    ConstPtrIterator& operator=(const ConstPtrIterator&) = default;
    ConstPtrIterator& operator=(ConstPtrIterator&&) = default;

    ConstPtrIterator& operator++();
    ConstPtrIterator operator++(int);

    bool operator!=(const ConstPtrIterator& rh)const;
    bool operator==(const ConstPtrIterator& rh)const;

    const T& operator*()const;
    const T& operator->()const;
protected:
    const T& t_get_val()const;
private:
    //start_ptr
    const T* t_ptr;
    //offset
    size_type t_pos;
};










template<class T, class size_type>
inline PtrIterator<T, size_type>& PtrIterator<T, size_type>::operator++()
{
    ++t_pos;
    return *this;
}

template<class T, class size_type>
inline PtrIterator<T, size_type> PtrIterator<T, size_type>::operator++(int)
{
    auto old = *this;
    ++t_pos;
    return old;
}

template<class T, class size_type>
inline bool PtrIterator<T, size_type>::operator!=(const PtrIterator& rh) const
{
    return t_pos != rh.t_pos;
}

template<class T, class size_type>
inline bool PtrIterator<T, size_type>::operator==(const PtrIterator& rh) const
{
    return t_pos == rh.t_pos;
}

template<class T, class size_type>
inline T& PtrIterator<T, size_type>::operator*()
{
    return t_get_val();
}

template<class T, class size_type>
inline T& PtrIterator<T, size_type>::operator->()
{
    return t_get_val();
}

template<class T, class size_type>
inline const T& PtrIterator<T, size_type>::operator*() const
{
    return t_get_val();
}

template<class T, class size_type>
inline const T& PtrIterator<T, size_type>::operator->() const
{
    return t_get_val();
}

template<class T, class size_type>
inline T& PtrIterator<T, size_type>::t_get_val()
{
    return t_ptr[t_pos];
}

template<class T, class size_type>
inline const T& PtrIterator<T, size_type>::t_get_val() const
{
    return t_ptr[t_pos];
}



template<class T, class size_type>
inline ConstPtrIterator<T, size_type>::ConstPtrIterator(const T* ptr, size_type pos):
    t_ptr(ptr),
    t_pos(pos)
{}

template<class T, class size_type>
inline ConstPtrIterator<T, size_type>& ConstPtrIterator<T, size_type>::operator++()
{
    ++t_pos;
    return *this;
}

template<class T, class size_type>
inline ConstPtrIterator<T, size_type> ConstPtrIterator<T, size_type>::operator++(int)
{
    auto old = *this;
    ++t_pos;
    return old;
}

template<class T, class size_type>
inline bool ConstPtrIterator<T, size_type>::operator!=(const ConstPtrIterator& rh) const
{
    return t_pos != rh.t_pos;
}

template<class T, class size_type>
inline bool ConstPtrIterator<T, size_type>::operator==(const ConstPtrIterator& rh) const
{
    return t_pos == rh.t_pos;
}

template<class T, class size_type>
inline const T& ConstPtrIterator<T, size_type>::operator*() const
{
    return t_get_val();
}

template<class T, class size_type>
inline const T& ConstPtrIterator<T, size_type>::operator->() const
{
    return t_get_val();
}

template<class T, class size_type>
inline const T& ConstPtrIterator<T, size_type>::t_get_val() const
{
    return t_ptr[t_pos];
}
