/*
Question:- Given an unsorted array and a number n, find if there exists a pair of elements in the array whose difference is n.
Solution coded by:- Aniket Jain
*/

#include <iostream>
#include <cmath>

using namespace std;

void swap(int *xp, int *yp) 
{ 
    int temp = *xp; 
    *xp = *yp; 
    *yp = temp; 
} 

void insertionSort(int *arr, int s, int e, char c = 'a'){
    if(c == 'd'){
        for(int i = s+1; i < e; i++){
            int j = i;
            while(arr[i] > arr[i-1] && i != s){
                swap(&arr[i], &arr[i-1]);
                i--;
            }
            i = j;
        }
    }
    else{
        for(int i = s+1; i < e; i++){
            int j = i;
            while(arr[i] < arr[i-1] && i != s){
                swap(&arr[i], &arr[i-1]);
                i--;
            }
            i = j;
        }
    }
}

bool checkPair(int *arr, int n, int x){
    insertionSort(arr, 0, n);
    int i = 0; 
    int j = n-1;
    while(i < j){
        if(arr[j] - arr[i] == x)
            return true;
        else if(arr[j] - arr[i] < x)
            i++;
        else
            j--;
    }
    return false;

}

int main(){
    int n;
    cout << "Enter the size of the array:- ";
    cin >> n;
    int *arr = new int[n];
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    int x;
    cout << "Enter X:- ";
    cin >> x;
    cout << boolalpha << checkPair(arr, n, x);
}