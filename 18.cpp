/*
Question:- Given an array that is sorted and then rotated around an unknown point. Find if the array has a pair with a given sum ‘x’. 
           It may be assumed that all elements in the array are distinct.
Solution coded by:- Aniket Jain
*/

#include <iostream>

using namespace std;

bool getpair(int *arr, int n, int sum){
    int p;
    for(p = 0; p < n - 1; p++)
        if(arr[p] > arr[p+1])
            break;
    int l = (p + 1) % n;
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