/*
Question:- You are given an array prices where prices[i] is the price of a given stock on the ith day.
           You want to maximize your profit by choosing a single day to buy one stock and choosing a different day 
           in the future to sell that stock.
           Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.
Solution coded by:- Aniket Jain
*/

#include <iostream>

using namespace std;

int returnmaxprofit(int *arr, int n){
    int maxprofit = INT16_MIN;
    int x = 0;
    int y = 1;
    while(y < n){
        int h = arr[y] - arr[x];
        if(h < 0)
            x=y;
        else
            if(maxprofit < h)
                maxprofit = h;
        y++;
    }
    if(maxprofit < 0)
        return 0;
    return maxprofit;
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
    cout << "The Maximum Profit can be:- " << returnmaxprofit(arr, size);
    return 0;
}