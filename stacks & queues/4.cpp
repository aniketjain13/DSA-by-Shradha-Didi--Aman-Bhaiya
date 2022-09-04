/*
Question:- Given a Queue Q containing N elements. The task is to reverse the Queue. Your task is to complete the function rev(), that reverses the N elements of the queue.
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
    private:
        node* top;
    public:
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
        int peek(){
            if(top == nullptr)
                return -1;
            return top->val;
        }
        bool isEmpty(){
            if(top == nullptr)
                return true;
            return false;
        }
};

queue stackReverseQueue(queue p){
    stack st;
    while(!p.isEmpty())
        st.push(p.del());
    while(!st.isEmpty())
        p.insert(st.pop());
    return p;
}

int main(){

    int n;
    cout << "Enter the size of the queue:- ";
    cin >> n;
    queue q;
    while(n--){
        int h;
        cout << "Enter the value:- ";
        cin >> h;
        q.insert(h);
    }
    q.display();
    q = stackReverseQueue(q);
    q.display();
    return 0;
}
