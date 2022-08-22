/*
Question:- Perform Counting Sort.
Solution coded by:- Aniket Jain
*/

#include <iostream>

using namespace std;

int max(int *arr, int s, int e){
    int max = INT_MIN;
    for(int i = s; i < e; i++)
        if(max < arr[i])
            max = arr[i];
    return max;
}

int min(int *arr, int s, int e){
    int min = INT_MAX;
    for(int i = s; i < e; i++)
        if(min > arr[i])
            min = arr[i];
    return min;
}

void countingSort(int *arr, int n){
    int max_v = max(arr, 0, n);
    int min_v = min(arr, 0, n);
    int range = max_v - min_v + 1;
    int *auxArr = new int[range]{0};
    int *resArr = new int[n];
    for(int i = 0; i < n; i++)
        auxArr[arr[i] - min_v]++;
        
    for(int i = 1; i < range; i++)
        auxArr[i] += auxArr[i-1];
    
    for(int i = n-1; i >= 0; i--){
        resArr[auxArr[arr[i] - min_v] - 1] = arr[i];
        auxArr[arr[i] - min_v]--;
    }

    for(int i = 0; i < n; i++)
        arr[i] = resArr[i]; 
}

int main(){
    int n;
    cout << "Enter the size of the array:- ";
    cin >> n;
    int *arr = new int[n];
    cout << "Enter the array\n";
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    countingSort(arr, n);
    cout << "The sorted array is:-\n";
    for(int i = 0; i < n; i++)
        cout << arr[i] << " ";
    return 0;
}
