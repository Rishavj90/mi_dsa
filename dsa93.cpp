#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node* next;
    Node(int x) {  data = x;  next = NULL; }
};

int getCount(struct Node* head) {
    int size = 0;
    Node* i = head;
    while(i != NULL){
        size++;
        i= i->next;
    }
    return size;
}

bool searchKey(int n, Node* head, int key) {
    Node* i = head;
    while(i != NULL){
        if(i->data == key) return true;
        i= i->next;
    }
    return false;
}