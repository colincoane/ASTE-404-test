#include <iostream>
#include "Vec.h"


/**
 * Tests vector operations from "Vec.h"
 * @param num_args number of command line input arguments
 * @param args actual input arguments: note, this is unimportant here
 * */
int main(int num_args, char **args) {
    double3 a{0,1,2}; //!< Initialize vector \f$ \vec{a} \f$
    double3 b{0,0,1}; //!< Initialize vector \f$ \vec{b} \f$
    std::cout<<a-b<<std::endl; //!< Perform vector subtraction and output to command line
    std::cout<<dot(a,b)<<std::endl; //!< Perform dot product
    return 0;
}