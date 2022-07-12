/*
Question:- Given an integer array nums, find the contiguous subarray 
(containing at least one number) which has the largest sum and return its sum.
Solution coded by:- Aniket Jain
*/

#include <iostream>

using namespace std;

int getsum(int *arr, int n){
    int currsum = 0;
    int maxsum = INT16_MIN;
    for(int i = 0; i < n; i++){
        currsum += arr[i];
        if(currsum > maxsum)
            maxsum = currsum;
        if(currsum < 0){
            currsum = 0;
        }
    }
    return maxsum; 
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
    cout << "Maximum sum of a subarray is:- " << getsum(arr, size);
    return 0;
}