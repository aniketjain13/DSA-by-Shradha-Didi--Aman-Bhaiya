/*
Question:- Given a linked list of 0s, 1s and 2s, sort it.
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
    void sort(){
        node* n = head;
        int z = 0;
        int o = 0;
        int t = 0;
        while(n){
            if(n->val == 0)
                z++;
            else if(n->val == 1)
                o++;
            else
                t++;
            n = n->next;
        }
        list l;
        for(int i = 0; i < z; i++)
            l.insert(0);
        for(int i = 0; i < o; i++)
            l.insert(1);
        for(int i = 0; i < t; i++)
            l.insert(2);
        head = l.head;
    }
};

int main(){
    list l1;
    l1.insert(0);
    l1.insert(1);
    l1.insert(0);
    l1.insert(2);
    l1.insert(1);
    l1.display();
    l1.sort();
    l1.display();
    return 0;
}