/*
QUESTION:Write a function to find the longest common prefix string amongst an array of strings.
         If there is no common prefix, return an empty string "".
Solution coded by:- Aniket Jain
*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

string longestCommonPrefix(vector<string>& strs) {
        
        string out = strs[0];
        for(int i = 1; i < strs.size(); i++){
            string h = "";
            for(int j = 0; j < strs[i].length(); j++){
                if(out[j] == strs[i][j]){
                    h += out[j];
                }
                else
                    break;
            }
            out = h;
        }
        return out;
    }

int main(){
    int n;
    cout << "Enter the number of strings: ";
    cin >> n;
    vector<string> strs(n);
    cout << "Enter strings:- ";
    for(int i = 0; i < n; i++)
        cin >> strs[i];
    cout << longestCommonPrefix(strs);
    return 0;
}