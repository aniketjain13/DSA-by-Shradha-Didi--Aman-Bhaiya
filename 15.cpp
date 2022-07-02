/*
Question:- Given the array nums after the possible rotation and an integer target, return the index of target if it is in nums,
           or -1 if it is not in nums.
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
        return low;
    if(high == low)
        return low;
    int mid = (high + low) / 2;
    if(arr[mid] >= arr[0])
        return findpivot(arr, mid+1, high);
    return findpivot(arr, low, mid);
}

int pivotedbinarysearch(int *arr, int n, int key){
    int pivot;
    if(arr[0] < arr[n-1])
    {
        pivot = 0;
        return binarySearch(arr, 0, n-1, key);
    }    
    else
    {   
        pivot = findpivot(arr, 0, n-1);
        if(key == arr[pivot])
            return pivot;
        if(key == arr[0])
            return 0;
        if(key < arr[0])
            return binarySearch(arr, pivot+1, n-1, key);
        return binarySearch(arr, 0, pivot-1, key); 
    }
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