/*
Question:- You are given a read only array of n integers from 1 to n.
           Each integer appears exactly once except A which appears twice and B which is missing.
           Return A and B.
Solution coded by:- Aniket Jain
*/

#include <iostream>

using namespace std;

struct Pair{
    int a,b;
};

Pair returnpair(int* arr, int n){
    int16_t temp;
    int16_t s2 = 0, sp2 = 0;
    for(int i = 0; i < n; i++){
        temp = arr[i];
        s2 += temp;
        sp2 += (temp*temp);
        temp = i + 1;
        s2 -= temp;
        sp2 -= (temp*temp);
    }
    sp2 = sp2 / s2;
    Pair p;
    p.a = (sp2 + s2)/2;
    p.b = sp2 - p.a;
    return p; 
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
    Pair p = returnpair(arr, size);
    cout << "A:"<<p.a<<"\nB:"<<p.b; 
    return 0;
}