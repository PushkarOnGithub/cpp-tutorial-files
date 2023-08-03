#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
    /* sorting: 
                    Time           avg Time     Aux. space
    merge sort :    O(nlogn)        O(nlogn)    O(1)      
    Quick sort :    O(n^2)          O(nlogn)    O(1)
    insertion sort: O(n^2)          O(n^2)      O(1)
    heap sort :     O(nlogn)        O(nlogn)    O(1)
    selection sort: O(n^2)          O(n^2)      O(1)*/

    int arr[10];
    for(int i = 9;i>=0;i--){
        arr[9-i] = i;
    }
    
    int n = sizeof(arr)/sizeof(arr[0]);
    int l;
    vector<int> vect(arr, arr+n);   // include vector to use it

    sort(arr, arr+10);             // sort(start_index, end_endex)
    
    sort(vect.begin(),vect.end(), greater<int>());  // Sorting the Vector in Descending order

    reverse(arr, arr+9);   //reverse(first_iterator, last_iterator) – To reverse a vector. 

    cout<<binary_search(arr, arr+9, 5)<<endl;    //  binary_search(first_iterator, last_iterator, x) – Tests whether x exists in sorted vector or not
    
    cout<<*max_element(arr, arr+9)<<endl;  // *max_element (first_iterator, last_iterator) – To find the maximum element of a vector.

    cout<<*min_element(arr, arr+9)<<endl;  // *min_element (first_iterator, last_iterator) – To find the minimum element of a vector.

    cout<<accumulate(arr, arr+9, 0)<<endl; // accumulate(first_iterator, last_iterator, initial value of sum) – Does the summation of vector elements

    cout<<count(arr, arr+9, 2)<<endl;   //count(first_iterator, last_iterator,x) – To count the occurrences of x in vector

    cout<<find(arr, arr+9, 5)<<endl;    //Returns an iterator to the first occurrence of x in vector and points to last address of vector ((name_of_vector).end()) if element is not present in vector

    cout<<lower_bound(arr, arr+9, 3)<<endl;  //lower_bound(first_iterator, last_iterator, x) – returns an iterator pointing to the first element in the range [first,last) which         has a value not less than ‘x’

    cout<<upper_bound(arr, arr+9, 4)<<endl;  //upper_bound(first_iterator, last_iterator, x) – returns an iterator pointing to the first element in the range [first,last)                  which has a value greater than ‘x’

    vect.erase(vect.begin() + 2);   // arr.erase(position to be deleted) – This erases selected element in vector and shifts and resizes the vector elements accordingly 

    vect.erase(unique(vect.begin(),vect.end()),vect.end());  // arr.erase(unique(arr.begin(),arr.end()),arr.end()) – This erases the duplicate occurrences in sorted vector in a single line.

    cout<<distance(vect.begin(), vect.begin()+3);  //distance(first_iterator,desired_position) – It returns the distance of desired position from the first iterator.This function               is very useful while finding the index. 
    cin>>l;
    return 0;
}
