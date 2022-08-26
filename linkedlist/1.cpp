/*
Question:- Given the head of a singly linked list, reverse the list, and return the reversed list.
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
    void reverseList(){
        node* p = head;
        if(p){
            node* nhead = new node(p->val);
            p = p->next;
            while(p){
                nhead = insertb(nhead, p->val);
                p = p->next;
            }
            head = nhead;
        }
    }
};

int main(){
    list l;
    l.insert(1);
    l.insert(2);
    l.insert(3);
    l.insert(4);
    l.insert(5);
    l.display();
    l.reverseList();
    l.display();
    return 0;
}