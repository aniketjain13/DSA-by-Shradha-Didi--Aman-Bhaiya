/*
Question:- Given a sorted array and a value x, the ceiling of x is the smallest element in an array greater than or equal to x, and the floor 
is the greatest element smaller than or equal to x. Assume that the array is sorted in non-decreasing order. Write efficient functions to find the floor and ceiling of x. 
Solution coded by:- Aniket Jain
*/

#include <iostream>
#include <cmath>

using namespace std;

int binarySearch(int *arr, int low, int high, int key)
{
    if (high < low)
        return -1;
    int mid = (low + high)/2;
    if (arr[mid] >= key && arr[mid - 1] <= key)
        return mid;
    if (key > arr[mid])
        return binarySearch(arr, (mid + 1), high, key);
    return binarySearch(arr, low, (mid - 1), key);
}
 

int findCeil(int *arr, int n, int x){
    if(arr[0] > x)
        return 0;
    return binarySearch(arr, 0, n-1, x);
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
    int h = findCeil(arr, n, x);
    if(h == -1)
        cout << "The array does not contain a ceil value for the given x";
    else
        cout << "The ceil value is present at: " << h+1;
}