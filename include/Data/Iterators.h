#pragma once

template <class T, class size_type>
class PtrIterator {
public:
    PtrIterator(PtrIterator&&) = default;
    PtrIterator(const PtrIterator&) = default;
    PtrIterator(T* ptr, size_type pos) : t_ptr(ptr), t_pos(pos) {}
    ~PtrIterator() = default;

    PtrIterator& operator=(const PtrIterator&) = default;
    PtrIterator& operator=(PtrIterator&&) = default;


    PtrIterator& operator++() {
        ++t_pos;
        return *this;
    }
    PtrIterator operator++(int) {
        auto old = *this;
        ++t_pos;
        return old;
    }

    bool operator!=(const PtrIterator& rh)const { return t_pos != rh.t_pos; }
    bool operator==(const PtrIterator& rh)const { return t_pos == rh.t_pos; }


    T& operator*() { return t_get_val(); }
    T& operator->() { return t_get_val(); }


    const T& operator*()const { return t_get_val(); }
    const T& operator->()const { return t_get_val(); }
protected:
    T& t_get_val() { return t_ptr[t_pos]; }
    const T& t_get_val()const { return t_ptr[t_pos]; }
private:
    T* t_ptr;
    size_type t_pos;
};

template <class T, class size_type>
class ConstPtrIterator {
public:
    ConstPtrIterator(ConstPtrIterator&&) = default;
    ConstPtrIterator(const ConstPtrIterator&) = default;
    ConstPtrIterator(const T* ptr, size_type pos) : t_ptr(ptr), t_pos(pos) {}
    ~ConstPtrIterator() = default;

    ConstPtrIterator& operator=(const ConstPtrIterator&) = default;
    ConstPtrIterator& operator=(ConstPtrIterator&&) = default;

    ConstPtrIterator& operator++() {
        ++t_pos;
        return *this;
    }
    ConstPtrIterator operator++(int) {
        auto old = *this;
        ++t_pos;
        return old;
    }

    bool operator!=(const ConstPtrIterator& rh)const { return t_pos != rh.t_pos; }
    bool operator==(const ConstPtrIterator& rh)const { return t_pos == rh.t_pos; }

    const T& operator*()const { return t_get_val(); }
    const T& operator->()const {return t_get_val();}
protected:
    const T& t_get_val()const { return t_ptr[t_pos]; }
private:
    const T* t_ptr;
    size_type t_pos;
};
