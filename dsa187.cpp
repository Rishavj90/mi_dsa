#include <bits/stdc++.h>
using namespace std;


class LRUCache{
private:
    class Node{
    public:
        int key;
        int value;
        Node* next;
        Node* prev;
        Node(int a, int b){
            key = a;
            value = b;
            next = nullptr;
            prev = nullptr; 
        }
    };
    int n;
    unordered_map<int, Node*>mpp;
    Node* head;
    Node* tail;

public:
    LRUCache(int capacity){
        n = capacity;
        head = new Node(-1,-1);
        tail = new Node(-1,-1);
        head->next = tail;
        tail->prev = head;
    }

    void moveToHead(Node*head, Node*theNode){
        Node* theFirst = head->next;
        Node* thePrev = theNode->prev;
        Node* theNext = theNode->next;

        head->next = theNode;
        theNode->next = theFirst;
        theFirst->prev = theNode;
        theNode->prev = head;

        thePrev->next = theNext;
        theNext->prev = thePrev;
        return;
    }

    void addNode(Node*head, Node*theNode){
        Node* theFirst = head->next;

        head->next = theNode;
        theNode->next = theFirst;
        theFirst->prev = theNode;
        theNode->prev = head;
        return;
    }

    void removeNode(Node*theNode, Node*tail){
        Node* thePrev = theNode->prev;

        thePrev->next = tail;
        tail->prev = thePrev;
        delete theNode;
        return;
    }
    
    int get(int key) {
        if(mpp.find(key) != mpp.end()){
            if(mpp[key]->prev != head)moveToHead(head,mpp[key]);
            return mpp[key]->value;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(mpp.find(key) != mpp.end()){
            Node* theNode = mpp[key];
            theNode->value = value;

            if(mpp[key]->prev != head)moveToHead(head,mpp[key]);
            return;
        }
        if(mpp.size() >= n){
            Node* theNode = tail->prev;
            mpp.erase(theNode->key);
            removeNode(theNode,tail);
        }
        Node* new_node = new Node(key, value);
        addNode(head,new_node);
        mpp[key] = new_node;
        return;
    }
};

int main(){
    LRUCache* a = new LRUCache(1);
    a->put(2,1);

}