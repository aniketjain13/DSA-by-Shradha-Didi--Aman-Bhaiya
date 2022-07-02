/*
Question:- Given the sorted rotated array nums of unique elements, return the minimum element of this array.
           You must write an algorithm that runs in O(log n) time.
Solution coded by:- Aniket Jain
*/

#include <iostream>

using namespace std;

int binarySearch(int *arr, int low, int high)
{
    if(high < low)
        return arr[low];
    if (high == low)
        return arr[low];
    int mid = (low + high)/2;
    if (arr[mid] >= arr[0])
        return binarySearch(arr, mid+1, high);
    return binarySearch(arr,low, mid);
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
    if(arr[size-1] > arr[0])
        cout << "The smallest element in the rotated array is:- " << arr[0];
    else
        cout << "The smallest element in the rotated array is:- " << binarySearch(arr, 0, size-1);
    return 0;
}