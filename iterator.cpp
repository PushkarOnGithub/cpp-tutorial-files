#include<iostream>
#include<unordered_map>
#include<vector>
#include<string>

using namespace std;

int main(){
    unordered_map<string, int> ourmap;
    ourmap["abc"] = 1;
    ourmap["abc2"] = 2;
    ourmap["abc3"] = 3;
    ourmap["abc4"] = 4;
    ourmap["abc5"] = 5;

    // to get the values stored in the map we have to use the iterator
    unordered_map<string, int> :: iterator it = ourmap.begin();  // creating an iterator and assigning it the value of first element of the map
    while(it != ourmap.end()){    // .end() method points to the element after last element
        cout<<"Key : "<<it->first<<"    Value : "<<it->second<<endl;
        it++;
    }

    // find method returns an iterator pointing to the found value
    unordered_map<string, int> :: iterator it1 = ourmap.find("abc2");
    ourmap.erase(it1);

    // similarly we can do this for vector, set, unordered_set etc...

    vector<int> ourvector;
    ourvector.push_back(1);
    ourvector.push_back(2);
    ourvector.push_back(3);
    ourvector.push_back(4);
    ourvector.push_back(5);

    vector<int> :: iterator itv1 = ourvector.begin();
    while(itv1 != ourvector.end()){
        cout<<*itv1<<" ";
        itv1++;
    }
}