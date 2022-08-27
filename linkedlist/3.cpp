/*
Question:- You are given the heads of two sorted linked lists list1 and list2.
           Merge the two lists in a one sorted list. The list should be made by splicing together the nodes of the first two lists.
           Return the head of the merged linked list.
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
    void mergeTwoLists(node* list1, node* list2) {
        node* l1 = list1;
        node* l2 = list2;
        if(l1 == nullptr && l2 == nullptr)
        {}
        else if((l1 != nullptr && l2 == nullptr) || (l1 == nullptr && l2 != nullptr)){
            while(l1 != nullptr){
                insert(l1->val);
                l1 = l1->next;
            }
            while(l2 != nullptr){
                insert(l2->val);
                l2 = l2->next;
            }
        }
        else{
            while(l1 != nullptr && l2 != nullptr){
                if(l1->val < l2->val){
                    insert(l1->val);
                    l1 = l1->next;
                }
                else{
                    insert(l2->val);
                    l2 = l2->next;
                }
            }
            while(l1 != nullptr){
                insert(l1->val);
                l1 = l1->next;
            }
            while(l2 != nullptr){
                insert(l2->val);
                l2 = l2->next;
            }
        }
    }
};

int main(){
    list l1;
    l1.insert(1);
    l1.insert(2);
    l1.insert(3);
    l1.insert(4);
    l1.insert(5);
    list l2;
    l2.insert(1);
    l2.insert(2);
    l2.insert(13);
    l2.insert(14);
    l2.insert(15);
    list l3;
    l3.mergeTwoLists(l1.head, l2.head);
    l3.display();
    return 0;
}