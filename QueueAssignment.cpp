#include <iostream>
#include <bits/stdc++.h>
#include <queue>
#include <stack>
using namespace std;

int main(int argc, char const *argv[])
{
    queue<int>q1;
    stack<int>q2;
    q1.push(1);
    q1.push(2);
    q1.push(3);
    q1.push(4);
    q1.push(5);
    q2.push(q1.front()); q1.pop();
    q2.push(q1.front()); q1.pop();
    q2.push(q1.front()); q1.pop();
    q2.push(q1.front()); q1.pop();
    q2.push(q1.front()); q1.pop();
    for(int i =0;i<5;i++){
        cout<<q2.top()<<endl;
        q2.pop();
    }
    return 0;
}
