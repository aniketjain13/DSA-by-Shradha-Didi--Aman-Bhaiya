/*
Question:- Given n non-negative integers representing an elevation map where the width of each bar is 1, 
           compute how much water it can trap after raining.
Solution coded by:- Aniket Jain
*/

#include <iostream>

using namespace std;

int findmaxp(int *arr, int st, int end){
    int max = INT16_MIN, maxp;
    for(int i = st; i <= end; i++){
        if(max <= arr[i]){
            max = arr[i];
            maxp = i;
        }
    }
    return maxp;
}

int trap(int *arr, int n){
    int x = 0, y;
    y = findmaxp(arr, x+1, n-1);
    int sum = 0;
    while(x < n-1){
        int i;
        for(i = x+1; i < y; i++){
            if(arr[i] >= arr[x]){
                break;
            }
            else{
                if(arr[x] < arr[y]){
                    sum += arr[x] - arr[i];
                }
                else{
                    sum += arr[y] - arr[i];
                }
            }
        }
        x = i;
        if(x == y){
            y = findmaxp(arr, x+1, n-1);
        }
    }
    return sum;
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
    cout << "The unit of water stored is:- " << trap(arr, size);
    return 0;
}