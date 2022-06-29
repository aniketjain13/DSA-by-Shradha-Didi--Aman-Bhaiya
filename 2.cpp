/*
Question:- Write a program to reverse an array or string
Solution coded by:- Aniket Jain
*/

#include <iostream>

using namespace std;

int* reverse(int *arr, int n){
    for(int i = 0; i < n/2; i++){
        int h = arr[i];
        arr[i] = arr[n-1-i];
        arr[n-1-i] = h;
    }
    return arr;
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
    arr = reverse(arr, size);
    cout << "The reversed array is:- ";
    for(int i = 0; i < size; i++){
        cout << arr[i] << " ";
    }
    return 0;
}