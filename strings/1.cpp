/*
Question:- Given a string s, return true if it is a palindrome, or false otherwise.
Solution coded by:- Aniket Jain
*/

#include <iostream>
#include <string>

using namespace std;

string regex_lower(string s){
    string h = "";
    for(int i = 0; i < s.length(); i++){
        if(s[i] >= 'A' && s[i] <= 'Z')
            h += (s[i]+32); 
        else if((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= '0' && s[i] <= '9'))
            h += s[i];
    }
    return h;
}

bool checkpalindrome(string s){
    s = regex_lower(s);
    int n = s.length()-1;
    for(int i = 0; i <= n/2; i++){
        if(s[i] != s[n-i])
            return false;
    }
    return true;
}

int main(){
    string s;
    cout << "Enter a string:- ";
    getline(cin, s);
    cout << boolalpha << checkpalindrome(s);
    return 0;
}