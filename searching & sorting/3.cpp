/*
Question:- Given three arrays sorted in non-decreasing order, print all common elements in these arrays.
Solution coded by:- Aniket Jain
*/

#include <iostream>

using namespace std;

void findCommon(int *a, int *b, int *c, int n1, int n2, int n3){
    int i = 0, j = 0, k = 0;
    int p1 = INT_MIN, p2 = INT_MIN, p3 = INT_MIN;
    while(i < n1 && j < n2 && k < n3){

        while(a[i] == p1)
            i++;
        while(b[j] == p2)
            j++;
        while(c[k] == p3)
            k++;
        
        if(a[i] == b[j] && b[j] == c[k]){
            cout << a[i] <<" ";
            i++;
            j++;
            k++;
        }

        if(a[i] < b[j] && a[i] < c[k])
            i++;
        else if(b[j] < c[k])
            j++;
        else 
            k++;
    }
}

int main(){
    int n1, n2, n3;
    cout << "Enter the size of the array 1:- ";
    cin >> n1;
    int *arr1 = new int[n1];
    for(int i = 0; i < n1; i++)
        cin >> arr1[i];
    
    cout << "Enter the size of the array 2:- ";
    cin >> n2;
    int *arr2 = new int[n2];
    for(int i = 0; i < n2; i++)
        cin >> arr2[i];
    
    cout << "Enter the size of the array 3:- ";
    cin >> n3;
    int *arr3 = new int[n3];
    for(int i = 0; i < n3; i++)
        cin >> arr3[i];
    
    findCommon(arr1, arr2, arr3, n1, n2, n3);

    return 0;
}