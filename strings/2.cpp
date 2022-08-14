/*
Question:- Given two strings s and t, return true if t is an anagram of s, and false otherwise.
Solution coded by:- Aniket Jain
*/

#include <iostream>
#include <string>
#include <map>

using namespace std;

bool isAnagram(string s, string t) {
        int l1 = s.length();
        int l2 = t.length();
        if(l1 != l2)
            return false;
        
        map<char, int> m1, m2;
        for(int i = 0; i < s.length(); i++){
            m1[s[i]]++;
            m2[t[i]]++;    
        }
        if(m1 == m2)
            return true;
        return false;
    }

int main(){
    string s, t;
    cout << "Enter string 1:- ";
    getline(cin, s);
    cout << "Enter string 2:- ";
    getline(cin, t);
    cout << boolalpha << isAnagram(s, t);
    return 0;
}