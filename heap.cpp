//
// Created by Adam on 2019-12-03.
//
#include "heap.hpp"


template <typename T>
ostream& operator<<(ostream& os, const heap<T>& data){
    for(auto it = data.begin(); it != data.end(); ++it){
        os << *it + " ";
    }
    os << endl;
    return os;
}
