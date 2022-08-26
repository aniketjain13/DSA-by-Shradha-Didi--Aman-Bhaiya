/*
Question:- Given head, the head of a linked list, determine if the linked list has a cycle in it.
           There is a cycle in a linked list if there is some node in the list that can be reached again by continuously following the next pointer. 
           Internally, pos is used to denote the index of the node that tail's next pointer is connected to. Note that pos is not passed as a parameter.
           Return true if there is a cycle in the linked list. Otherwise, return false.
Solution coded by:- Aniket Jain
*/

#include <iostream>

using namespace std;

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

class list{
    public:
    node *head;
    list(){
        head = nullptr;
    }
    void insert(int v){
        if(head == nullptr){
            node* p = new node(v);
            head = p;
        }
        else{
            node* p = new node(v);
            node* q = head;
            while(q->next != nullptr){
                q = q->next;
            }
            q->next = p;

        }
    }
    void display(){
        node* p = head;
        while(p){
            cout << p->val << " ";
            p = p->next;
        }
        cout << endl;
    }
    node* insertb(node *head, int val){
        node *p = new node(val, head);
        return p;
    }
    
    bool hasCycle() {
        if(head == nullptr)
            return false;
        node* slow = head;
        node* fast = head->next;
        while(slow != fast){
            if(slow == nullptr || fast == nullptr || fast->next == nullptr)
                return false;
            slow = slow->next;
            fast = fast->next->next;
        }
        return true;
    }
};

int main(){
    list l;
    l.insert(1);
    l.insert(2);
    l.insert(3);
    l.insert(4);
    l.insert(5);
    l.head->next->next->next->next->next = l.head;
    cout << boolalpha << l.hasCycle();
    return 0;
}