#include <iostream>
#include <list>
#include "heap.hpp"

int main() {

    list <int> list1;
    list1.push_back( 1);
    list1.push_back( 28);
    list1.push_back( 2);
    list1.push_back( 4);
    list1.push_back( 9);
    list1.push_back( 7);
    list1.push_back( 5);

    heap<int,std::list<int>> hospitalPatients(list1);
    cout << hospitalPatients;
    return 0;
}