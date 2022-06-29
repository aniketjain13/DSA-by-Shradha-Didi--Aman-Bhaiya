
/* 
Question:- Find a maximum and minimum element in an array
Solution coded by:- Aniket Jain
*/

#include <iostream>

using namespace std;    

struct Pair{
    int max;
    int min;
};

Pair getminmax(int *arr, int n){
    Pair maxmin;
    if(n == 1){
        maxmin.max = arr[0];
        maxmin.min = arr[0];
    }
    else{
        if(arr[0] < arr[1]){
            maxmin.max = arr[1];
            maxmin.min = arr[0];
        }
        else{
            maxmin.max = arr[0];
            maxmin.min = arr[1];
        }
        for(int i = 2; i < n; i++){
            if(arr[i] > maxmin.max)
                maxmin.max = arr[i];
            else if(arr[i] < maxmin.min)
                maxmin.min = arr[i];
        }
    }
    return maxmin;
}

int main(){
    int size;
    cout << "Enter the size of the array:- ";
    cin >> size;
    cout << "Enter the array:-\n ";
    int *arr = new int(size);
    for(int i = 0; i < size; i++){
        cin >> arr[i];
    }
    Pair mm = getminmax(arr, size);
    cout << "The maximum value in the array is:- " << mm.max << "\n";
    cout << "The minimum value in the array is:- " << mm.min << "\n";
    return 0;
}