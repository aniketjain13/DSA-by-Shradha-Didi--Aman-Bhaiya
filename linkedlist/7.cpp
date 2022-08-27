/*
Question:- Given two numbers represented by linked lists, write a function that returns the multiplication of these two linked lists.
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
    int max(){
        node* n = head;
        int max = INT_MIN;
        while(n){
            if(max < n->val)
                max = n->val;
            n = n->next;
        }
        return max;
    }
    int getNumber(){
        int number = head->val;
        node* n = head->next;
        while(n){
            number *= 10;
            number += n->val;
            n = n->next;
        }
        return number;
    }
};

int main(){
    list l1, l2;
    l1.insert(9);
    l1.insert(4);
    l1.insert(6);
    l2.insert(8);
    l2.insert(4);
    int n1 = l1.getNumber();
    int n2 = l2.getNumber();
    cout << n1*n2;
    return 0;
}