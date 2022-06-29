/*
Question:- Given an array of n integers where each value represents the number of chocolates 
in a packet. Each packet can have a variable number of chocolates. There are m students, 
the task is to distribute chocolate packets such that: 
->Each student gets one packet.
->The difference between the number of chocolates in the packet with maximum chocolates and 
packet with minimum chocolates given to the students is minimum.
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

void selectionSort(int* arr, int n) 
{ 
    int i, j, min_idx; 
  for (i = 0; i < n-1; i++) 
    { 
        min_idx = i; 
        for (j = i+1; j < n; j++) 
        if (arr[j] < arr[min_idx]) 
            min_idx = j; 
        swap(&arr[min_idx], &arr[i]); 
    } 
} 

int mindiff(int *arr, int n, int m){
    selectionSort(arr, n);
    int min = INT16_MAX;
    for(int i = 0; m+i-1 < n; i++){
        int h = arr[m-1+i] - arr[i];
        if(min > h)
            min = h;
    }
    return min;
}

int main(){
    int size, m;
    cout << "Enter the size of the array:- ";
    cin >> size;
    cout << "Enter the array:-\n";
    int *arr = new int(size);
    for(int i = 0; i < size; i++){
        cin >> arr[i];
    }
    cout << "Enter the number of students:- ";
    cin >> m;
    cout << "Minimum difference is:- " << mindiff(arr, size, m);
    return 0;
}