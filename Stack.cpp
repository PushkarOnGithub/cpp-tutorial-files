#include <iostream>
#include <bits/stdc++.h>
#include <stack>
using namespace std;

template <typename T>
class Stack_arr{

    T *data;
    int nextIndex;
    int capacity;
    public:

    Stack_arr(){
        data = new T[5];
        nextIndex = 0;
        capacity = 5;
    }

    int getSize(){
        return nextIndex;
    }

    bool is_empty(){
        return nextIndex == 0;
    }

    void push(T const data){
        if (nextIndex == capacity){
            T *newData = new T[capacity + 5];
            for(int i = 0;i< capacity;i++){
                newData[i] = this->data[i];
            }
            delete[] this->data;
            this -> data = newData;
            capacity += 5;

            // cout<< "Stack Full"<<endl;
            // return;
        }
        this -> data[nextIndex] = data;
        nextIndex++;
    }

    T pop(){
        if (nextIndex == 0){
            cout<< "Stack is Empty"<<endl;
            return 0;
        }
        nextIndex--;
        return this->data[nextIndex];
    }

    T top(){
        if(nextIndex == 0){
            cout<<"Stack is Empty"<<endl;
            return 0;
        }
        return this ->data[nextIndex-1];
    }

};

template <typename V>
class Node{
    public:
    V data;
    Node <V>*next;
    Node(V const data){
        this->data = data;
        this->next = NULL;
    }
};

template <typename T>
class Stack_LL{
    Node<T> *head;
    int size;
    public:

    Stack_LL(){
        size = 0;
        head = NULL;
    }

    int getSize(){
        return size;
    }

    T top(){
        if (size != 0) return head->data;
        cout<<"Stack is Empty1"<<endl;
    }

    void push(T data){
        size++;
        Node<T> *newNode = new Node<T>(data);
        newNode->next = head;
        head = newNode;
    }

    bool is_empty(){
        return size == 0;
    }

    T pop(){
        if (size != 0){
            Node<T> *temp = head;
            head = head -> next;
            T dat = (temp -> data);
            delete temp;
            size--;
            return dat;
        }
        cout<<"Stack is Empty"<<endl;
    }

};
int main()
{
    Stack_LL <int>s;
    // cout<<s.pop()<<endl;
    // cout<<s.top()<<endl;
    // s.push(100);
    // s.push(101);
    // s.push(102);
    // s.push(103);
    // cout<<s.getSize()<<endl;
    // cout<<s.pop()<<endl;
    // cout<<s.is_empty()<<endl;

    return 0;
}
