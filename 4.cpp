/*
Question:- Given an integer array nums, return true if any value appears at least twice
in the array, and return false if every element is distinct.
Solution coded by:- Aniket Jain
*/

#include <iostream>
#include <set>
#include <iterator>

using namespace std;

bool containduplicate(int *arr, int n){
    set<int> s;
    for(int i = 0; i < n; i++){
        if(s.count(arr[i])) 
            return true;
        s.insert(arr[i]);
    }
    return false;
}

int main(){
    int size;
    cout << "Enter the size of the array:- ";
    cin >> size;
    cout << "Enter the array:-\n";
    int *arr = new int(size);
    for(int i = 0; i < size; i++){
        cin >> arr[i];
    }
    if(containduplicate(arr, size))
        cout << "The array contains duplicates";
    else
        cout << "The array doesn't contain duplicates";
    return 0;
}