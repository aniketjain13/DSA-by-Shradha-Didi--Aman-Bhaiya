/*
Question:- Write a removeDuplicates() function that takes a list and deletes any duplicate nodes from the list. The list is not sorted. 
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
    void removeDuplicate(){
        int size = max();
        int* arr = new int[size+1]();
        node* n = head;
        while(n){
            if(arr[n->val] == 0){
                arr[n->val]++;
                n = n->next;
            }
            else{
                if(n->next == nullptr){
                    node* p = head;
                    while(p->next != n)
                        p = p->next;
                    p->next = NULL;
                    free(n);
                    break;
                }
                else
                    del(n);
            }
        }
    }
};

int main(){
    list l1;
    l1.insert(1);
    l1.insert(1);
    l1.insert(1);
    l1.insert(2);
    l1.insert(2);
    l1.display();
    l1.removeDuplicate();
    l1.display();
    return 0;
}