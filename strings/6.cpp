/*
QUESTION:Given a sentence in the form of a string, convert it into its equivalent mobile numeric keypad sequence. 
Solution coded by:- Aniket Jain
*/

#include <iostream>
#include <string>

using namespace std;

string getKeypad(string s){
    string keypad[] = {
        "2", "22", "222",
        "3", "33", "333",
        "4", "44", "444",
        "5", "55", "555",
        "6", "66", "666",
        "7", "77", "777","7777",
        "8", "88", "888",
        "9", "99", "999", "9999"
    };
    string h = "";
    for(int i = 0; i < s.length(); i++)
        h += keypad[s[i]-'A'];
    return h;
}

int main(){
    string s;
    cout << "Enter string:- ";
    getline(cin, s);
    cout << getKeypad(s);
    return 0;
}