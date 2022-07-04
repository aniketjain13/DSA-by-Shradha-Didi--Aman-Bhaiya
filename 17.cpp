/*
Question:- You are given an integer array height of length n. There are n vertical lines drawn 
           such that the two endpoints of the ith line are (i, 0) and (i, height[i]).
           Find two lines that together with the x-axis form a container, such that the container contains the most water.
           Return the maximum amount of water a container can store.
Solution coded by:- Aniket Jain
*/

#include <iostream>

using namespace std;

int maxArea(int *arr, int n) {
        int i,j;
        int max = INT16_MIN;
        for(i = 0, j = n-1; i < j;){
            if(arr[i] < arr[j]){
                if(max < arr[i] * (j-i))
                    max = arr[i] * (j-i);
                else
                    i++;
            }
            else{
                if(max < arr[j] * (j-i))
                    max = arr[j] * (j-i);
                else
                    j--;
            }
        }
        return max;    
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
    cout << "The maximum water stored is:- "<<maxArea(arr, size);
    return 0;
}