#include<iostream>
#include "BSTClass.h"
// #include "BinaryTreeClass.h"

using namespace std;

int main(){
    BST b;
    b.insert(4);
    b.insert(10);
    b.insert(5);
    b.insert(3);
    b.printClass();
    cout<<b.hasData(4)<<endl;
}