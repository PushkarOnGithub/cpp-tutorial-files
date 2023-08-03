#include<iostream>
#include<bits/stdc++.h>
#include<queue>
using namespace std;

int main()
{
    stack<int> s1;
    int n = 5;
    for(int i = 1;i < n+1;i++){
        s1.push(i*10);
    }
    stack<int> s3;
    stack<int> s2;
    for(int i = 0;i < n;i++){
        s3.push(s1.top());
        s1.pop();
    }
    for(int i = 0;i < n;i++){
        s2.push(s3.top());
        s3.pop();
    }
    return 0;
}
