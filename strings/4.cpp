/*
QUESTION:Given a string S. For each index i(1<=i<=N-1), erase it if s[i] is equal to s[i-1] in the string.
Solution coded by:- Aniket Jain
*/

#include <iostream>
#include <string>

using namespace std;

string removeConsecutiveCharacter(string s)
    {
        string h = "";
        int l = -1;
        for(int i = 0; i < s.length(); i++){
            h += s[i];
            l++;
            while(s[i+1] == h[l] && i+1 < s.length()){
                i++;
            }
        }
        return h;
    }

int main(){
    string s;
    cout << "Enter string:- ";
    getline(cin, s);
    cout << removeConsecutiveCharacter(s);
    return 0;
}