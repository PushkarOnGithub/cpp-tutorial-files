#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin>>s;
    int index = 0;
    int indexLast = s.size();
    for(int i = 0;i<s.size();i++,index++){
        if(s[index] == 'h'){
            break;
        }
    }
    for(int i = s.size();i>=0;i--,indexLast--){
        if(s[indexLast] == 'o'){
            break;
        }
    }
    string temp(s.begin() + index, s.begin()+indexLast+1);
    s = temp;
    unordered_map<char, int> m;
    string s2;s2.push_back('h');
    for(int i = 0;i<s.size();i++){
        if(s[i] != s2.back()){
            s2.push_back(s[i]);
        }
        m[s[i]]++;
    }
    if(m.size() != 4){
        cout<<"NO"<<endl;
        return 0;
    }
    auto it = m.begin();
    if(s2 != "helo" or m.find('l')->second < 2){
        cout<<"NO"<<endl;
        return 0;
    }
    cout<<"YES"<<endl;
    }