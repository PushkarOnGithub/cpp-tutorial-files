// the motive is to create a data structure supporting print(), insert(), replace()

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int solve(int n, int k){
    list<int> l;
    for(int i = 0;i<n;i++){
        l.push_back(i);
    }
    auto it = l.begin();
    while(l.size() != 1){
        for(int i = 1;i<k;i++){
            it++;
            if(it == l.end()){
                it = l.begin();
            }
            it = l.erase(it);
            if(it == l.end()){
                it = l.begin();
            }
        }
    }
    return *l.begin();
}

class list2{
    public:
    list<int> l;

    list2(int arr[], int size){
        for(int i = 0;i<size;i++){
            l.push_back(arr[i]);
        }
    }
    
    void insert(int data){
        this->l.push_back(data);
    }

    void replace(int data, list2 l){
        auto it = this->l.begin();
        for(int i = 0;i<this->l.size();i++){
            if(*it == data){
                break;
            }
            it++;
        }
        if(it == this->l.end()){
            cout<<"Element don't exist in the List"<<endl;
            return;
        }
        it = this->l.erase(it);
        auto it2 = l.l.begin();
        for(int i = 0;i<l.l.size();i++, it2++){
            this->l.insert(it, *it2);
        }
    }

    void print(){
        auto it = this->l.begin();
        for(int i = 0;i<this->l.size();i++,it++){
            cout<<*it<<", ";
        }
        cout<<endl;
    }
};

int main() {
    int arr[] = {1, 3, 5, 8};
    list2 l(arr, 4);
    l.print();
    int arr2[] = {12, 22,32};
    list2 l2(arr2, 3);
    l.replace(3, l2);
    l.print();
}
