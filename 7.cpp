/*
Question:- Given an array of integers nums, find the next permutation of nums.
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

void arrdisp(int *arr, int n){
    for(int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << "\n";
}

void rev(int *arr, int st, int end){
    while(st < end)
        swap(&arr[st++], &arr[end--]);
}

void findnext(int *arr, int n){
    if(arr[n-2] < arr[n-1])
        swap(&arr[n-2], &arr[n-1]);
    else{
        int i = n-2;
        while(i >= 0 && arr[i] >= arr[i+1])
            i--;
        int j = n-1;
        while(j >= i){
            if(arr[j] > arr[i])
                break;
            j--;
        }
        swap(&arr[i], &arr[j]);
        rev(arr, i+1, n-1);
    }
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
    findnext(arr, size);
    cout << "The next number is:-\n";
    arrdisp(arr, size);
    return 0;
}