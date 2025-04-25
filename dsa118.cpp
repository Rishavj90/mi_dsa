#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int val;
    Node* next;
    Node* random;
        
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

Node* copyRandomList(Node* head) {
    Node* i = head;
    //making duplicates
    while(i != nullptr){
        Node* dup = new Node(i->val);
        dup->next = i->next;
        i->next = dup;
        i = i->next->next;
    }
    //marking random
    i = head;
    while(i != nullptr){
        Node* dup_ran;
        if(i->random != nullptr)dup_ran = i->random->next;
        else dup_ran = i->random;
        i->next->random = dup_ran;
        i = i->next->next;
    }
    //separating the duplicates from the main LL
    Node* clone = new Node(-1);
    Node* j = clone;
    i = head;
    while(i != nullptr){
        j->next = i->next;
        i->next = i->next->next;
        j = j->next;
        i = i->next;
    }
    j->next = nullptr;
    return clone->next;
}