/*
Question:- An element in a sorted array can be found in O(log n) time via binary search.
But suppose we rotate an ascending order sorted array at some pivot unknown to you beforehand. So for instance, 1 2 3 4 5 might become 3 4 5 1 2. 
Devise a way to find an element in the rotated array in O(log n) time.
Solution coded by:- Aniket Jain
*/

#include <iostream>

using namespace std;

int binarySearch(int *arr, int low, int high, int key)
{
    if (high < low)
        return -1;
    int mid = (low + high)/2;
    if (key == arr[mid])
        return mid;
    if (key > arr[mid])
        return binarySearch(arr, (mid + 1), high, key);
    return binarySearch(arr, low, (mid - 1), key);
}
 
int findpivot(int *arr, int low, int high){
    if(high < low)
        return -1;
    if(high == low)
        return low;
    int mid = (high + low) / 2;
    if(arr[mid] > arr[mid+1])
        return mid+1;
    if(arr[mid] < arr[mid-1])
        return mid;
    if(arr[mid] < arr[high] || arr[mid] > arr[low])
        return findpivot(arr, mid+1, high);
    return findpivot(arr, low, mid-1);
}

int pivotedbinarysearch(int *arr, int n, int key){
    int pivot = findpivot(arr, 0, n-1);
    if(key == arr[pivot])
        return pivot;
    if(key == arr[0])
        return 0;
    if(key < arr[0])
        return binarySearch(arr, pivot+1, n-1, key);
    return binarySearch(arr, 0, pivot-1, key);
}

int main(){
    int size, key;
    cout << "Enter the size of the array:- ";
    cin >> size;
    cout << "Enter the array:-\n";
    int *arr = new int(size);
    for(int i = 0; i < size; i++){
        cin >> arr[i];
    }
    cout << "Enter the number to be found:- ";
    cin >> key;
    int h = pivotedbinarysearch(arr, size, key);
    if(h == -1){
        cout << "Number not found";
    }
    else
        cout << "Number found at "<<h+1;
    return 0;
}