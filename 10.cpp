/*
Question:- Given an integer array nums and an integer k, return the kth largest element in the array.
           Note that it is the kth largest element in the sorted order, not the kth distinct element.
Solution coded by:- Aniket Jain
*/

#include <iostream>

using namespace std;

void swap(int *xp, int *yp) 
{ 
    int temp = *xp; 
    *xp = *yp; 
    *yp = temp; 
} 

int getklargest(int *arr, int n, int k){
    int max, maxp;
    for(int i = 0; i < k; i++){
        max = INT16_MIN;
        maxp = -1;
        for(int j = 0; j < n-i; j++){
            if(max < arr[j]){
                max = arr[j];
                maxp = j;
            }
        }
        swap(&arr[n-i-1], &arr[maxp]);
    }
    return arr[n-k];
}

int main(){
    int size, k;
    cout << "Enter the size of the array:- ";
    cin >> size;
    cout << "Enter the array:-\n";
    int *arr = new int(size);
    for(int i = 0; i < size; i++){
        cin >> arr[i];
    }
    cout << "Enter value of k:- ";
    cin >> k;
    cout << "The "<<k<<"th largest number is: "<< getklargest(arr, size, k);
    return 0;
}