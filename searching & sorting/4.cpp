/*
Question:- Searching in an array where adjacent differ by at most k
Solution coded by:- Aniket Jain
*/

#include <iostream>
#include <cmath>

using namespace std;

int findElement(int *arr, int n, int x, int k){
    for(int i = 0; i < n;){
        if(arr[i] == x)
            return i;
        i += max(1, abs(arr[i] - x)/k);
    }
    return -1;
}

int main(){
    int n;
    cout << "Enter the size of the array:- ";
    cin >> n;
    int *arr = new int[n];
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    int x, k;
    cout << "Enter K:- ";
    cin >> k;
    cout << "Enter X:- ";
    cin >> x;
    int h = findElement(arr, n, x, k);
    if(h == -1)
        cout << "The entered element is not present";
    else
        cout << "The element is present at " << h;
}