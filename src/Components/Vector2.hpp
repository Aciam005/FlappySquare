#pragma once

template <typename T> class Vector2
{
    public:
    Vector2(T newX,T newY);

    /*
        @brief
        Normalizes the vector (ensures it's length is 1)
        Useful for getting directions
    */
    void Normalize();

    /*
        @brief
        Returns the length of the vector
    */
    T GetLength();

    private:

    public:
    T x,y;

    private:
};


