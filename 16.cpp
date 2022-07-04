/*
Question:- Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] 
           such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.
Solution coded by:- Aniket Jain
*/

#include <iostream>
#include <vector>

using namespace std;

void swap(int *xp, int *yp) 
{ 
    int temp = *xp; 
    *xp = *yp; 
    *yp = temp; 
} 

void selectionSort(int* arr, int n) 
{ 
    int i, j, min_idx; 
    for (i = 0; i < n-1; i++) 
    { 
        min_idx = i; 
        for (j = i+1; j < n; j++) 
        if (arr[j] < arr[min_idx]) 
            min_idx = j; 
        swap(&arr[min_idx], &arr[i]); 
    } 
} 

vector<vector<int>> threesum(int *arr, int n) {
        selectionSort(arr, n);
        vector<vector<int>> v;
        if(n < 3)
            return v;
        else if(n == 3)
        {
            if(arr[0]+arr[1]+arr[2] == 0)
                v.push_back({arr[0], arr[1], arr[2]});
            return v;
        }
        
        for(int i = 0; i < n-2; i++){
            int j = i+1;
            int k = n-1;
            while(j < k){
                if(arr[j] + arr[k] == -arr[i]){
                    v.push_back({arr[i], arr[j], arr[k]});
                    j++; k--;                
                    while(k > j && arr[k] == arr[k+1]) k--;
                    while(j < k && arr[j] == arr[j-1]) j++;
                }
                else if(arr[j] + arr[k] > -arr[i]){
                    k--;
                    while(k > j && arr[k] == arr[k+1]) k--;

                }
                else{
                    j++;
                    while(j < k && arr[j] == arr[j-1]) j++;
                }
            }
            while(i < n-2 && arr[i] == arr[i+1]) i++;
        }
        return v;
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
    vector<vector<int>> v = threesum(arr, size);
    for(int i = 0; i < v.size(); i++){
        for(int j = 0; j < 3; j++){
            cout<<v[i][j]<<" ";
        }
        cout << "\n";
    }
    return 0;
}