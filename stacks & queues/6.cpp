/*
Question:- Given an integer K and a queue of integers, we need to reverse the order of the first K elements of the queue, leaving the other elements in the same relative order.
Solution coded by:- Aniket Jain
*/

#include <iostream>
#include <string>

using namespace std;

//********************************************************************************
//  TO IMPLEMENT QUEUE AND STACK USING LINKED LIST
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
    int size;

    queue(){
        front = nullptr;
        rear = nullptr;
        size = 0;
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
        size++;
    }
    int del(){
        if(front == nullptr)
            return -1;
        node* q = front;
        front = front->next;
        size--;
        return q->val;
    }
    void display(){
        node* p = front;
        while(p){
            cout << p->val << " ";
            p = p->next;
        }
        cout << endl;
    }
    bool isEmpty(){
        if(front == nullptr)
            return true;
        return false;
    }
};

//********************************************************************************
//  TO IMPLEMENT STACK
//********************************************************************************
class stack{
    public:
        node* top;
        stack(){
            top = nullptr;
        }
        void push(int x){
            if(top == nullptr){
                node* p = new node(x);
                top = p;
            }
            else{
                node* p = new node(x);
                p->next = top;
                top = p;
            }
        }
        int pop(){
            if(top == nullptr)
                return -1;
            int h = top->val;
            top = top->next;
            return h;
        }
        bool isEmpty(){
            if(top == nullptr)
                return true;
            return false;
        }
};

queue modifyQueue(queue q, int k){
    stack st;
    while(k--)
        st.push(q.del());
    queue q1;
    while(!st.isEmpty())
        q1.insert(st.pop());
    while(!q.isEmpty())
        q1.insert(q.del());
    return q1;        
}

int main(){
    queue q;
    q.insert(1);
    q.insert(2);
    q.insert(3);
    q.insert(4);
    q.insert(5);
    int k;
    cout << "Enter the value K:- ";
    cin >> k;
    q.display();
    q = modifyQueue(q, k);
    q.display();
    return 0;
}