#include "Vector2f.hpp"
#include <math.h>

Vector2f::Vector2f(float x,float y): x(x) , y(y)  {}

Vector2f::Vector2f(Vector2f* other)
{
    this -> x = other -> x;
    this -> y = other -> y;
}

double Vector2f::GetLength()
{
    return (sqrt(x*x + y*y));
}

void Vector2f::Normalize()
{
    float length = this->GetLength();

    this->x = this->x / length;
    this->y = this->y / length;
}

Vector2f* Vector2f::Normalized()
{
    float length = this->GetLength();
    
    Vector2f* normalizedVector = new Vector2f(this->x / length , this->y / length);
    return normalizedVector;
}