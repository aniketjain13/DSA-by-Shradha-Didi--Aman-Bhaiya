/*
QUESTION:Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.
         An input string is valid if:
         Open brackets must be closed by the same type of brackets.
         Open brackets must be closed in the correct order.
Solution coded by:- Aniket Jain
*/

#include <iostream>
#include <string>
#include <stack>

using namespace std;

bool isValid(string s1) {
    stack<char> s;
    for(int i = 0; i < s1.length(); i++){
        if(s.empty())
            s.push(s1[i]);
        else{
            switch(s1[i]){
                case '}': if(s.top() == '{'){ s.pop();}
                        else{s.push(s1[i]);}
                    break;
                case ']': if(s.top() == '['){ s.pop();}
                        else{s.push(s1[i]);}
                    break;
                case ')': if(s.top() == '('){ s.pop();}
                        else{s.push(s1[i]);}
                    break;
                default: s.push(s1[i]);
                    break;
            }
        }
    }
    return s.empty();
}

int main(){
    string s;
    cout << "Enter string:- ";
    getline(cin, s);
    cout << boolalpha << isValid(s);
    return 0;
}