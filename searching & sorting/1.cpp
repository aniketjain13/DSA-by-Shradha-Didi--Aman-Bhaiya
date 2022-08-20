/*
Question:- Given two arrays of equal size n and an integer k. The task is to permute both arrays such that sum of their corresponding element is greater than or equal to k i.e a[i] + b[i] >= k. The task is print “Yes” if any such permutation exists, otherwise print “No”.
Solution coded by:- Aniket Jain
*/

#include <iostream>
#include <string>

using namespace std;

void swap(int *xp, int *yp) 
{ 
    int temp = *xp; 
    *xp = *yp; 
    *yp = temp; 
} 

void selectionSort(int* arr, int s, int n, char c) 
{ 
    if(c == 'd'){
        int i, j, max_idx;
        for (i = s; i < n-1; i++) 
        { 
            max_idx = i; 
            for (j = i+1; j < n; j++) 
                if (arr[j] > arr[max_idx]) 
                    max_idx = j; 
            swap(&arr[max_idx], &arr[i]); 
        } 
    }
    else{
        int i, j, min_idx;
        for (i = s; i < n-1; i++) 
        { 
            min_idx = i; 
            for (j = i+1; j < n; j++) 
                if (arr[j] < arr[min_idx]) 
                    min_idx = j; 
            swap(&arr[min_idx], &arr[i]); 
        } 
    }
} 

bool check(int *arr1, int *arr2, int n, int k){
    selectionSort(arr1, 0, n, 'a');
    selectionSort(arr2, 0, n, 'd');
    int flag = 1;
    for(int i = 0; i < n; i++){
        if(arr1[i] + arr2[i] < k){
            flag = 0;
            break;
        }
    }
    return flag;
        
}

int main(){
    int n, k;
    cout << "Enter the size of the array: ";
    cin >> n;
    cout << "Enter the first array: \n";
    int *arr1 = new int[n];
    for(int i = 0; i < n; i++)
        cin >> arr1[i];
    cout << "Enter the second array: \n";
    int *arr2 = new int[n];
    for(int i = 0; i < n; i++)
        cin >> arr2[i];
    cout << "Enter k: ";
    cin >> k;
    cout << boolalpha << check(arr1, arr2, n, k);
    return 0;
}