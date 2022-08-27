/*
Question:- Given a pointer to a node to be deleted, delete the node. Note that we don’t have a pointer to the head node.
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
    void del(node* p){
        node* q = p->next;
        p->val = q->val;
        p->next = q->next;
        free(q);
    }
};

int main(){
    list l1;
    l1.insert(1);
    l1.insert(2);
    l1.insert(3);
    l1.insert(4);
    l1.insert(5);
    l1.display();
    l1.del(l1.head->next);
    l1.display();
    return 0;
}