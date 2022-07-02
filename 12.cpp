/*
Question:- Write a program to reverse an array or string
Solution coded by:- Aniket Jain
*/

#include <iostream>

using namespace std;

void arrdisp(int *arr, int n){
    for(int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << "\n";
}

int32_t * getproductself(int32_t *arr, int n){
    int32_t *p = new int32_t(n);
    int32_t prod = 1;
    for(int i = 0; i < n; i++){
        p[i] = prod;
        prod *= arr[i];
    }
    prod = 1;
    for(int i = n-1; i > -1; i--){
        p[i] *= prod;
        prod *= arr[i];
    }
    return p;
}

int main(){
    int size;
    cout << "Enter the size of the array:- ";
    cin >> size;
    cout << "Enter the array:-\n";
    int32_t *arr = new int32_t(size);
    for(int i = 0; i < size; i++){
        cin >> arr[i];
    }
    arr = getproductself(arr, size);
    cout << "The result is:-\n";
    arrdisp(arr, size);
    return 0;
}