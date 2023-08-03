#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>
using namespace std;

vector<int> remove_duplicates(int *a, int size){
    vector<int> output;
    unordered_map<int, bool> seen;
    for(int i = 0; i<size; i++){
        if(seen.count(a[i])){
            continue;
        }
        output.push_back(a[i]);
        seen[a[i]] = true;
    }
    return output;
}

vector<int> intersection(int *arr1, int size1, int *arr2, int size2){
    unordered_map<int, 
}

int main()
{
    unordered_map<string, int> ourmap;

    //insert - access
    pair<string, int> p("abc", 1);
    ourmap.insert(p);
    cout<<"size : "<<ourmap.size()<<endl;
    ourmap["push"] = 2;
    cout<<"size : "<<ourmap.size()<<endl;
    cout<<ourmap["push"]<<endl;
    // cout<<ourmap.at("kar")<<endl; // gives an error if elment is not present
    cout<<ourmap["kar"]<<endl;  // [] fetches the element if present if not it adds the element into the map

    //delete 
    ourmap.erase("kar");

    //find
    if(ourmap.count("push")>0){
        cout<<"'push' exits"<<endl;
    }

    // remove duplicates from an int array problem
    int a[] = {1, 2, 3, 3, 2, 1, 4, 8, 5, 6, 6};
    int size = 11;
    vector<int> output = remove_duplicates(a, size);
    for(int i =0 ;i<output.size();i++){
        cout<<output[i]<<" ";
    }
    cout<<endl;

    // problem: maximum frequency number
    // int a[] = {1, 2, 3, 3, 2, 1, 4, 8, 5, 6, 6};
    vector<int> uniques = remove_duplicates(a, size);
    unordered_map<int, int> freq;
    for(int i = 0;i<size;i++){
        if(freq.count(a[i]) == 0){
            freq[a[i]] = 1;
        }
        else{
            freq[a[i]] = freq[a[i]] + 1;
        }
    }
    int max_freq = 0, max_freq_num = 0;
    for(int i = 0;i<uniques.size();i++){
        if(freq[uniques[i]] > max_freq){
            max_freq = freq[uniques[i]];
            max_freq_num = uniques[i];
        }
    }
    cout<<"Max freq : "<<max_freq<<"  Max freq number : "<<max_freq_num<<endl;

    //problem: find the intersection
    int arr1[] = {1, 2, 3, 6, 3, 7, 2, 10};
    int size_arr1 = 8;
    int arr1[] = {2, 4, 5, 7, 6, 2, 3};
    int size_arr2 = 7;


    return 0;
}
