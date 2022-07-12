/*
Question:- Given an array that is sorted and then rotated around an unknown point. Find if the array has a pair with a given sum ‘x’. 
           It may be assumed that all elements in the array are distinct.
Solution coded by:- Aniket Jain
*/

#include <iostream>

using namespace std;

int findpivot(int *arr, int low, int high){
    if(high < low)
        return low;
    if(high == low)
        return low;
    int mid = (high + low) / 2;
    if(arr[mid] >= arr[0])
        return findpivot(arr, mid+1, high);
    return findpivot(arr, low, mid);
}

bool getpair(int *arr, int n, int sum){
    int p = findpivot(arr, 0, n) - 1;
    int l = p + 1;
    int h = p;
    while(l != h){
        if(arr[l] + arr[h] == sum)
            return true;
        else if(arr[l] + arr[h] < sum)
            l = (l + 1) % n;
        else
            h = (n + h - 1) % n; 
    }
    return false;
}

int main(){
    int size, sum;
    cout << "Enter the size of the array:- ";
    cin >> size;
    cout << "Enter the array:-\n";
    int *arr = new int[size];
    for(int i = 0; i < size; i++){
        cin >> arr[i];
    }
    cout << "Enter the sum:-\n";
    cin >> sum;
    cout << boolalpha << getpair(arr, size, sum); 
    return 0;
}