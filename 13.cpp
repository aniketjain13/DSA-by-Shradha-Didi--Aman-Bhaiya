/*
Question:- Given an integer array nums, find a contiguous non-empty subarray within the array that has the largest product, and return the product.
           The test cases are generated so that the answer will fit in a 32-bit integer.
           A subarray is a contiguous subsequence of the array.
Solution coded by:- Aniket Jain
*/

#include <iostream>

using namespace std;

int max(int a, int b, int c){
    if(a > b && a > c)
        return a;
    else if(b > c)
        return b;
    return c;
}

int min(int a, int b, int c){
    if(a < b && a < c)
        return a;
    else if(b < c)
        return b;
    return c;
}

int getmul(int *arr, int n){
    int max_so_far = arr[0];
    int max_last = arr[0];
    int min_last = arr[0];

    for(int i = 1; i < n; i++){
        int temp = max(arr[i], arr[i]*max_last, arr[i]*min_last);
        min_last = min(arr[i], arr[i]*max_last, arr[i]*min_last);
        max_last = temp;
        if(max_last > max_so_far)
            max_so_far = max_last;
    }
    return max_so_far;
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
    cout << "The biggest product is:- " << getmul(arr, size); 
    return 0;
}