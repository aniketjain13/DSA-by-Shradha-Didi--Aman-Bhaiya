/*
Question:- Implement Stack and Queue using Deque
Solution coded by:- Aniket Jain
*/

#include <iostream>
#include <string>

using namespace std;

//********************************************************************************
//  TO IMPLEMENT DEQUE USING LINKED LIST
//********************************************************************************
class doublyNode{
    public:
    int val;
    doublyNode* next;
    doublyNode* previous;
    doublyNode(){
        val = 0;
        next = nullptr;
        previous = nullptr;
    }
    doublyNode(int v){
        val = v;
        next = nullptr;
        previous = nullptr;
    }
};


//********************************************************************************
//  TO IMPLEMENT DEQUE 
//********************************************************************************
class deque{
    public:
    doublyNode* front;
    doublyNode* rear;

    deque(){
        front = nullptr;
        rear = nullptr;
    }

    void insertFront(int x){
        if(front == nullptr){
            doublyNode* p = new doublyNode(x);
            front = p;
            rear = p;
        }
        else{
            doublyNode* p = new doublyNode(x);
            p->next = front;
            front->previous = p;
            front = p;
        }
    }
    void insertRear(int x){
        if(front == nullptr){
            doublyNode* p = new doublyNode(x);
            front = p;
            rear = p;
        }
        else{
            doublyNode* p = new doublyNode(x);
            rear->next = p;
            p->previous = rear;
            rear = p;
        }
    }
    int deleteFront(){
        if(front == nullptr)
            return -1;
        int h = front->val;
        front->previous = nullptr;
        front = front->next;
        return h;
    }
    int deletRear(){
        if(front == nullptr)
            return -1;
        int h = rear->val;
        rear->next = nullptr;
        rear = rear->previous;
        return h;
    }
    void display(){
        doublyNode* p = front;
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
//  TO IMPLEMENT QUEUE USING DEQUE 
//********************************************************************************
class queue: public deque{
    public:
    void insert(int x){
        insertRear(x);
    }
    int deleteQ(){
        return deleteFront();
    }
};

//********************************************************************************
//  TO IMPLEMENT STACK USING DEQUE 
//********************************************************************************
class stack: public deque{
    public:
    void push(int x){
        insertRear(x);
    }
    int pop(){
        return deletRear();
    }
};

int main(){
    stack st;
    queue q;
    int n, h;
    while(true){
        cout << "Press 1. to push in stack\n";
        cout << "Press 2. to pop from stack\n";
        cout << "Press 3. to display stack\n";
        cout << "Press 4. to insert in queue\n";
        cout << "Press 5. to delete from queue\n";
        cout << "Press 6. to display queue\n";
        cout << "Press 0. to exit\n";
        cin >> n;
        switch (n)
        {
        case 1:
            cout << "Enter the value to be pushed in stack:- ";
            cin >> h;
            st.push(h);
            break;
        case 2:
            cout << "Poped value is:- (-1 means stack is empty) "<< st.pop() << endl;
            break;
        case 3:
            st.display();
            break;
        case 4:
            cout << "Enter the value to be pushed in stack:- ";
            cin >> h;
            q.insert(h);
            break;
        case 5:
            cout << "Deleted value is:- (-1 means queue is empty) "<< q.deleteQ() << endl;
            break;
        case 6:
            q.display();
            break;
        case 0: break;
        default:
            break;
        }
        if(n == 0)
            break;
    }
    return 0;
}