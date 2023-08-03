# include<iostream>
#include <bits/stdc++.h>
#include <queue>
using namespace std;

template <typename T>
class Queue_arr{
    T *data;
    int size;
    int capacity;
    int firstindex;   // index which will be popped.
    int nextindex;

    public:

    Queue_arr(){
        data = new T[5];
        size = 0;
        capacity = 5;
        firstindex = -1;    // -1 because queue is empty hence dequeue can not be done.
        nextindex=0;
    }

    int getsize(){
        return size;
    }

    bool isEmpty(){
        return size == 0;
    }

    void enqueue(T data){
        if(size == capacity){
            T *newData = new T[capacity + 10];
            int j = 0;
            for(int i = firstindex; i<capacity;i++){
                newData[j] = this->data[i];
                j++;
            }
            for(int i = 0;i<firstindex;i++){
                newData[j] = this->data[i];
                j++;
            }
            delete []this->data;
            this->data = newData;
            nextindex = capacity;
            capacity = capacity + 10;
        }
        this->data[nextindex] = data;
        nextindex = (nextindex+1)%capacity;

        if(firstindex == -1){
            firstindex = 0;
        }
        size++;
    }

    T dequeue(){
        if (size==0){
            cout<<"Queue is empty"<<endl;
            return 0;
        }
        firstindex--;
        size--;
        
        return 0;

    }

    T front(){
        if(size!=0) return data[firstindex];
        cout<<"Queue is Empty"<<endl;
    }

};

int main(int argc, char const *argv[])
{
    queue<int> q;
    q.push(10);
    q.push(20);
    q.push(30);

    cout<<q.front()<<endl;
    q.pop();
    cout<<q.front()<<endl;
    cout<<q.size()<<endl;
    cout<<q.empty()<<endl;

    // q.enqueue(10);
    // q.enqueue(20);
    // q.enqueue(30);
    // q.enqueue(30);
    // q.enqueue(30);
    // q.enqueue(30);
    // cout<<q.getsize()<<endl;
    // cout<<q.isEmpty()<<endl;
    // cout<<q.dequeue()<<endl;
    // cout<<q.front()<<endl;
    // cout<<q.<<endl;
    return 0;
}
