/*
Question:- Implement a last-in-first-out (LIFO) stack using only two queues. The implemented stack should support all the functions of a normal stack (push, top, pop, and empty).
Solution coded by:- Aniket Jain
*/

#include <iostream>
#include <string>

using namespace std;

//********************************************************************************
//  TO IMPLEMENT QUEUE USING LINKED LIST
//********************************************************************************
class node{
    public:
    int val;
    node* next;
    node(){
        val = 0;
        next = nullptr;
    }
    node(int v){
        val = v;
        next = nullptr;
    }
    node(int v, node* n){
        val = v;
        next = n;
    }
};

//********************************************************************************
//  TO IMPLEMENT QUEUE 
//********************************************************************************
class queue{
    public:
    node *front;
    node *rear;

    queue(){
        front = nullptr;
        rear = nullptr;
    }
    void insert(int v){
        if(front == nullptr){
            node* p = new node(v);
            front = p;
            rear = p;
        }
        else{
            node* p = new node(v);
            rear->next = p;
            rear = p;
        }
    }
    int del(){
        if(front == nullptr)
            return -1;
        node* q = front;
        front = front->next;
        return q->val;
    }
    int peek(){
        if(front == nullptr)
            return -1;
        return front->val;
    }
    bool isEmpty(){
        if(front == nullptr)
            return true;
        return false;
    }
};

//********************************************************************************
//  TO IMPLEMENT STACK USIGN TWO QUEUES 
//********************************************************************************
class MyStack {
    
    public:
    queue q1;
    queue q2;
    MyStack() {
    }
    
    void push(int x) {
        q2.insert(x);
        while(!q1.isEmpty()){
            q2.insert(q1.del());
        }
        while(!q2.isEmpty()){
            q1.insert(q2.del());
        }
    }
    
    int pop() {
        return q1.del();
    }
    
    int top() {
        return q1.peek();
    }
    
    bool empty() {
        return q1.isEmpty();
    }
};
int main(){

    MyStack s;
    int n;
    while(true){
        cout << "Press 1. to push in stack\n";
        cout << "Press 2. to pop from stack\n";
        cout << "Press 3. to get the top of stack\n";
        cout << "Press 4. to check if stack is empty\n";
        cout << "Press 0. to exit\n";
        cin >> n;
        switch (n)
        {
        case 1:
            int h;
            cout << "Enter the value:- ";
            cin >> h;
            s.push(h); 
            break;
        case 2:
            if(s.top() == -1)
                cout << "Stack is empty\n";
            else
                cout << s.pop() << endl;
            break;
        case 3:
            if(s.top() == -1)
                cout << "Stack is empty\n";
            else
                cout << s.top() << endl;
            break;
        case 4:
            cout << boolalpha << s.empty() << endl; 
            break;
        case 0: break;
        default:
            cout << "Wrong Input Enter Again\n";
            break;
        }
        if(n == 0)
         break;
    }
    return 0;
}
