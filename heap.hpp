//
// Created by Adam on 2019-12-03.
//

#include <vector>
#include <algorithm>
#include <iostream>


using namespace std;

#ifndef HEAP_HEAP_HPP
#define HEAP_HEAP_HPP


template <typename T, class Tcontainer>
class heap {

private:
    vector<T> data;
    int dataSize = 0;

    void heapify(int index){
        if(checkHeadNode()){
            fix_heap_up(index);
        } else {
            fix_heap_down(index);
        }
    }
    bool checkHeadNode(){
        T leftN = data[this->leftNode(0)];
        T rightN= data[this->rightNode(0)];
        return leftN < data[0] && rightN < data[0];
    }
    void fix_heap_up(int i){
//        cout << i << endl;
        if (i != 0 && data[this->parentNode(i)] < data[i]) {
            swap(i, this->parentNode(i));
            fix_heap_up(this->parentNode(i));
        }
    }
    void fix_heap_down(int i){
        int l = leftNode(i);
        int r = rightNode(i);
        int smallest = i;
        if (l < dataSize && data[l] < data[i])
            smallest = l;
        if (r < dataSize && data[r] < data[smallest])
            smallest = r;
        if (smallest != i)
        {
            swap(i, smallest);
            fix_heap_down(smallest);
        }
    }
    //bool larger(const T& t1, const T& t2){return t1 > t2;}
    int leftNode(int i) { return 2*i + 1;}
    int rightNode(int i) { return 2*i + 2;}
    int parentNode(int i) { return (i-1)/2;}
    void swap(int i, int j)
    {
        T temp = data[i];
        data[j] = temp;
        data[i] = temp;
    }
    template<typename ToType, typename FromType>
    ToType container_cast(const FromType& source)
    {
        return ToType(source.begin(), source.end(), source.get_allocator());
    }

public:
    heap(const Tcontainer& tc){
        vector<T> newData = container_cast<std::vector<T> >(tc);
        for(int i = 0; i < newData.size(); ++i){
            this->push(newData[i]);
        }
    }
    void push(T newElement) {
        //add el to vector
        data.push_back(newElement);
//        dataSize++;
        fix_heap_up(data.size()-1);
    }
    T pop(){
        T head = data[0];
        swap(head, data[--dataSize]);
        data.pop_back();
        heapify(0);
        return head;
    }
    int size(){return dataSize;}
    bool is_empty(){return dataSize <= 0;}
    void clear(){
        //remove all el in heap...no memory leaks
    }
    friend std::ostream& operator<<(std::ostream& os, const heap<T, Tcontainer>& myHeap) {
        for (int i = 0; i < myHeap.data.size(); ++i)
            os << myHeap.data[i] << " ";
        return os;
    }
};





#endif //HEAP_HEAP_HPP
