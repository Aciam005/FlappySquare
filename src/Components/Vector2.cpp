#include "Vector2.hpp"
#include "math.h"

template <typename T>
Vector2<T>::Vector2(T newX,T newY) : x(newX) , y(newY)
{}

template <typename T>
T Vector2<T>::GetLength()
{
    return sqrt(pow(x,2) + pow(y,2));
}

template <typename T>
void Vector2<T>::Normalize()
{
    T length = GetLength();

    x = x/length;
    y = y/length;
}

