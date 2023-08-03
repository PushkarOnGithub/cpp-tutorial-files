#include <iostream>
using namespace std;

template<typename T>
class Pair{
    public:
    T first;
    T second;

    Pair(T first, T second){
        this->first = first;
        this->second = second;
    }
};