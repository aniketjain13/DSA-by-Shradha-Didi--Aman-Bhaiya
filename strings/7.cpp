/*
QUESTION:Write an efficient program to print all the duplicates and their counts in the input string.
Solution coded by:- Aniket Jain
*/

#include <iostream>
#include <string>
#include <map>

using namespace std;

void countDupli(string s){
    map<char, int> m;
    for(int i = 0; i < s.length(); i++)
        m[s[i]]++;
    for(auto it : m){
        if(it.second > 1)
            cout << it.first << ", count is: " << it.second << endl;
    }
}

int main(){
    string s;
    cout << "Enter string:- ";
    getline(cin, s);
    countDupli(s);
    return 0;
}