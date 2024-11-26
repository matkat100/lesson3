#include "Vector.h"
#include <iostream>

// Constructor
Vector::Vector(int n)
{
    _resizeFactor = (n < 2) ? 2 : n;
    _capacity = _resizeFactor;
    _size = 0;
    _elements = new int[_capacity];
}

// Destructor
Vector::~Vector() 
{
    delete[] _elements;
}


int Vector::size() const 
{
    return _size;
}

int Vector::capacity() const
{
    return _capacity;
}

int Vector::resizeFactor() const 
{
    return _resizeFactor;
}

bool Vector::empty() const 
{
    return _size == 0;
}

void Vector::push_back(const int& val) 
{
    if (_size == _capacity) 
    {
        reserve(_capacity + _resizeFactor);
    }
    _elements[_size] = val;
    _size++;
}

int Vector::pop_back()
{
    if (_size == 0) 
    {
        std::cerr << "empty vector pop_back: error\n";
        return -9999;
    }
    return _elements[--_size];
}

void Vector::reserve(int n) 
{
    if (n <= _capacity) return;

    int new_capacity = _capacity;
    while (new_capacity < n) 
    {
        new_capacity += _resizeFactor; 
    }

    int* new_elements = new int[new_capacity];
    for (int i = 0; i < _size; i++)
    {
        new_elements[i] = _elements[i];
    }

    delete[] _elements;
    _elements = new_elements;
    _capacity = new_capacity;
}

void Vector::resize(int n)
{
    if (n > _capacity)
    {
        reserve(n);
    }
    _size = n;
}

void Vector::resize(int n, const int& val) 
{
    resize(n);
    for (int i = _size; i < n; i++)
    {
        _elements[i] = val;
    }
}

void Vector::assign(const int val) 
{
    for (int i = 0; i < _size; i++) 
    {
        _elements[i] = val;
    }
}

// Copy Constructor
Vector::Vector(const Vector& other) 
{
    _resizeFactor = other._resizeFactor;
    _capacity = other._capacity;
    _size = other._size;
    _elements = new int[_capacity];
    for (int i = 0; i < _size; i++)
    {
        _elements[i] = other._elements[i];
    }
}

Vector& Vector::operator=(const Vector& other)
{
    if (this == &other) return *this;

    delete[] _elements;

    _resizeFactor = other._resizeFactor;
    _capacity = other._capacity;
    _size = other._size;
    _elements = new int[_capacity];
    for (int i = 0; i < _size; i++) 
    {
        _elements[i] = other._elements[i];
    }

    return *this;
}


int& Vector::operator[](int n) const
{
    if (n < 0 || n >= _size) 
    {
        return _elements[0];
    }
    return _elements[n];
}

