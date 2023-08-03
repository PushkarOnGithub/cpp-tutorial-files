#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Darr{
    int *data;
    int nextIndex;
    int capacity;

    public:

    Darr(): nextIndex(0), capacity(2){
        data = new int[capacity];
    }
    void add(int num){
        data[nextIndex] = num;
        nextIndex++;
        if (nextIndex == 2){
            nextIndex = 0;
            capacity+=2;
        }
    }
    void print(){
        for(int k = 0;k<(capacity-2+nextIndex);k++){
            cout<<data[k]<<"    ";
        }
        cout<<endl;
    }

};


class Polynomial{
    int *degree;
    int capacity = 2;

    public:

    Polynomial(){
        degree = new int[5];
        for(int i = 0;i<5;i++){
            degree[i] = 0;
        }
    }

    void setcoef(int const a, int const x){
        if (x>capacity){
            int *newdegree = new int[x];
            for(int k = 0;k<x;k++){
                newdegree[k] = 0;
            }
            for(int k = 0; k<capacity+1;k++){
                newdegree[k] = degree[k];
            }
            delete [] degree;
            degree = newdegree;
            capacity = x;
        }
        degree[x] = a;
    }

    Polynomial &operator+(Polynomial const &p1){
        int *newPoly = new int[max(this->capacity , p1.capacity) + 1];
        for(int k = 0;k<(this->capacity + p1.capacity + 1);k++){
            newPoly[k] = 0;
        }
        for(int k = 0; k<max(this->capacity+1, p1.capacity+1);k++){
            newPoly[k] = this->degree[k] + p1.degree[k];    
        }
        
        for(int k = 0; k < max(capacity+1,p1.capacity+1);k++){
            degree[k] += p1.degree[k];
        }
        return *this;
    }
    Polynomial &operator-(Polynomial const &p1){
        for(int k = 0; k < max(capacity+1, p1.capacity+1);k++){
            degree[k] -= p1.degree[k];
        }
        return *this;
    }

    Polynomial operator*(Polynomial const &p1){
        int *newPoly = new int[this->capacity + p1.capacity + 1];
        cout<<capacity+p1.capacity<<endl;
        for(int k = 0;k<(this->capacity + p1.capacity + 1);k++){
            newPoly[k] = 0;
        }
        for(int k = 0; k<this->capacity+1;k++){
            for(int l = 0; l < p1.capacity+1;l++){
                // cout<<this->degree[k]*p1.degree[l]<<endl;
                int coe = this->degree[k] * p1.degree[l];
                int deg = k + l;
                newPoly[deg] += coe;
            }
        }
        Polynomial newP;
        for(int k = 0; k<capacity+p1.capacity+1;k++){
            newP.setcoef(newPoly[k], k);
        }
        delete[] newPoly;
        return newP;
    }
    // Polynomial & operator=(Polynomial const &p1){
        
    // }
    void print(){
        if (degree[0]!=0) {cout<<degree[0];}
        for(int k = 1; k<capacity+1;k++){
            if (degree[k]!=0){cout<<" + "<<degree[k]<<"x^"<<k;}
        }
        cout<<endl;
    }
};

class Node{
    int data;
    Node *next;

    public:
    Node(int const x){
        this -> data = x;
        
    }

    int getData(int const index){
        int d;
        for(int i = 0; i < index ; i++){
            
        }
    }

};


int main(int argc, char const *argv[])
{
    // Darr a;
    // a.add(2);
    // a.add(2);
    // a.add(2);
    // // a.add(2);
    // a.print();

    // Polynomial p2;
    // p2.setcoef(1, 0);
    // p2.setcoef(1, 1);
    // p2.setcoef(1, 2);
    // p2.setcoef(1, 3);

    // Polynomial p3;
    // p3.setcoef(1, 0);
    // p3.setcoef(1, 1);
    // p3.setcoef(1, 5);
    // p3.setcoef(1, 3);

    // p2.print();
    // p3.print();

    // Polynomial p4 = p2+p3;
    // p4.print();



    return 0;
}