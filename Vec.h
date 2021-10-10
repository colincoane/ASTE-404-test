#ifndef _VEC_H
#define _VEC_H

#include <ostream>
#include <math.h>

template<typename T>

/**
 * Creates a generic 3D vector of type T (ex. int, float, double, etc)
 * 
 * Implements vector operations such as addition, subtraction, and dot product */
class _vec3{        // generic 3D vector of type T
public:

    _vec3<T>() : d{0,0,0} {}
    //!< Default constructor for 3D vector
    _vec3<T>(T a, T b, T c) : d{a,b,c} {}
    //!< Constructor

    T& operator[] (int i) {return d[i];} //!< Overloaded [] operator
    T operator[] (int i) const {return d[i];} //!< Overloaded [] operator

    /**
     * Implements vector addition for the equation
      \f$ \vec{a} + \vec{b} = \vec{c} \f$
     * @param a 3D vector
     * @param b another 3D vector
     * @return Returns 3D vector obtained from adding a and b
     */
    friend _vec3<T> operator+(const _vec3<T>&a, const _vec3<T>&b) {
        return _vec3<T>(a[0] + b[0], a[1] + b[1], a[2] + b[2]);
    }

    /**
     * Implements vector subtraction for the equation
      \f$ \vec{a} - \vec{b} = \vec{c} \f$
     * @param a 3D vector
     * @param b another 3D vector
     * @return Returns 3D vector obtained by subtracting b from a
     */
    friend _vec3<T> operator-(const _vec3<T>&a, const _vec3<T>&b) {
        return _vec3<T>(a[0] - b[0], a[1] - b[1], a[2] - b[2]);
    }

    /**
     * Overloads << operator to simplify writing vector \f$ \vec{a} \f$ to the screen
     * @param out output stream
     * @param a 3D vector
     * @return prints elements of 3D vector a to out
     */
    friend std::ostream& operator<<(std::ostream &out, const _vec3<T>&a) {
        out<<a[0]<<" "<<a[1]<<" "<<a[2]; return out;
    }

    /**
     * Implements the dot product of two vectors
      \f$ \vec{a} \cdot \vec{b} = a_1 b_1 + a_2 b_2 + a_3 b_3 \f$
     * @param a 3D vector
     * @param b another 3D vector
     * @return Returns scalar obtained from dot product of a with b
     */
    friend T dot(const _vec3<T>&a, const _vec3<T>&b) {
        return a[0]*b[0] + a[1]*b[1] + a[2]*b[2];
    }
    
    /**
     * Returns vector magnitude
     * @param a 3D vector
     * @return vector magnitude \f$ |\vec{a}| = \sqrt{\vec{a} \cdot \vec{a}} \f$
     * */
    friend double mag(const _vec3<T>&a) {
        return sqrt(dot(a,a));
    }

protected:
    T d[3];
    //!< Initializes 3 element array d of type T
};

using double3 = _vec3<double>;      // assign a nickname

#endif