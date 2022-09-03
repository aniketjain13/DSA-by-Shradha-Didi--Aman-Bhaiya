/*
Question:- Evaluation of Postfix Expression
Solution coded by:- Aniket Jain
*/

#include <iostream>
#include <string>

using namespace std;

class stack{
    private:
        int *arr;
        int top;
        int size;
    
    public:
        stack(int n){
            arr = new int[n];
            size = n;
            top = -1;
        }

        void push(int n){
            if(top+1 == size)
                cout << "Stack is full\n";
            else{
                top++;
                arr[top] = n;
            }
        }
        int pop(){
            if(top == -1)
                return -1;
            top--;
            return arr[top+1]; 
        }
};


void evaluate(string s){
    stack st(s.length());
    for(int i = 0; i < s.length(); i++){
        if(s[i] >= '0' && s[i] <= '9'){
            int h = s[i] - 48;
            i++;
            while(s[i] != ' '){
                h = h*10 + int(s[i] - 48);
                i++;
            }
            st.push(h);
        }
        else{
            if(s[i] != ' '){
                int b = st.pop();
                int a = st.pop();
                switch(s[i]){
                    case '+':
                        st.push(a+b);
                        break;
                    case '-':
                        st.push(a-b);
                        break;
                    case '/':
                        st.push(a/b);
                        break;
                    case '*':
                        st.push(a*b);
                        break;
                }
            }
        }
    }

    cout << "The result is:- " << st.pop();
    
}

int main(){
    
    cout << "Enter the expression:-\n";
    string s;
    getline(cin, s);
    evaluate(s);
    return 0;
}