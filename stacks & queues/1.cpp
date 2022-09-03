/*
Question:- Create a data structure twoStacks that represents two stacks. Implementation of twoStacks should use only one array
Solution coded by:- Aniket Jain
*/

#include <iostream>

using namespace std;

class twoStack{
    private:
        int *arr;
        int top1;
        int top2;
        int size;
    
    public:
        twoStack(int n){
            arr = new int[n];
            size = n;
            top1 = -1;
            top2 = n;
        }

        void push1(int n){
            if(top1+1 == top2)
                cout << "Stack is full\n";
            else{
                top1++;
                arr[top1] = n;
            }
        }
        void push2(int n){
            if(top2-1 == top1)
                cout << "Stack is full\n";
            else{
                top2--;
                arr[top2] = n;
            }
        }
        void pop1(){
            if(top1 == -1)
                cout << "Stack 1 is empty\n";
            else{
                cout << "The poped value is:- " << arr[top1] << endl;
                top1--;
            }
        }
        void pop2(){
            if(top2 == size)
                cout << "Stack 2 is empty\n";
            else{
                cout << "The poped value is:- " << arr[top2] << endl;
                top2++;
            }
        }
};

int main(){

    int n;
    cout << "Enter the size of the twoStack: ";
    cin >> n;

    twoStack s(n);
   
    int k, h;

    while(1){
        cout << "Press 1. to push in stack 1\n";
        cout << "Press 2. to push in stack 2\n";
        cout << "Press 3. to pop from stack 1\n";
        cout << "Press 4. to pop from stack 2\n";
        cout << "Press 0. to exit\n";
        cin >> k;
        switch (k)
        {
        case 1: 
            cout << "Enter the value:- ";
            cin >> h;
            s.push1(h);
            break;
        case 2: 
            cout << "Enter the value:- ";
            cin >> h;
            s.push2(h);
            break;
        case 3: s.pop1();
            break;
        case 4: s.pop2();
            break;
        case 0: break;
        default:
            cout << "Wrong input\nEnter again\n";
            break;
        }
        if(k == 0)
            break;
    }

    return 0;
}