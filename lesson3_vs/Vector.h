#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>

class Vector
{
private:
    // Fields
    int* _elements;
    int _capacity; // Total memory allocated
    int _size; // Size of vector to access
    int _resizeFactor; // How many cells to add when need to reallocate
public:
    // Constructor and Destructor
    Vector(int n = 10);
    ~Vector();

    // Accessors
    int size() const;   // Return size of vector
    int capacity() const;   // Return capacity of vector
    int resizeFactor() const; // Return vector's resize factor
    bool empty() const; // Returns true if size = 0

    // Modifiers
    void push_back(const int& val); // Adds element at the end of the vector
    int pop_back(); // Removes and returns the last element of the vector
    void reserve(const int n); // Change the capacity
    void resize(const int n); // Change _size to n, unless n is greater than the vector's capacity
    void resize(const int n, const int& val); // Same as above, if new elements added their value is val
    void assign(const int val); // Assigns val to all elements

    // Copy constructor and assignment operator
    Vector(const Vector& other);
    Vector& operator=(const Vector& other);

    // Element Access
    int& operator[](int n) const; // nth element
};

#endif
