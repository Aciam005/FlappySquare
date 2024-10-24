#ifndef VECTOR2_H
#define VECTOR2_H

class Vector2f 
{
    //methods
    public:

    Vector2f(float x,float y);
    
    //copy c-tor
    Vector2f(Vector2f* other);

    //Returns the length of the vector
    double GetLength();
    
    /*
        @brief
        Normalizes the vector (ensures it's length is 1)
        useful for getting directions
    */
    void Normalize();


    /*
        @brief
        Returns the normalised vector,without changing the original
    */
    Vector2f* Normalized();

    private:

    //member variables

    public:
    float x;
    float y;

    private:
};

#endif