#include <bits/stdc++.h>
using namespace std;

class LFUCache {
    private:
    class Node{
        public:
        int key, value, frq;
        Node *next, *prev;
        Node(int _key, int _value){
            key = _key, value = _value, frq = 0;
            next = nullptr;
            prev = nullptr;
        }
    };
    int cap, minFreq = INT_MAX;
    unordered_map<int, Node*>dict;
    unordered_map<int, pair<Node*, Node*>>freq_mpp;  //{freq, {head, tail}}
public:
    LFUCache(int capacity) {
        cap = capacity;
    }

    void addNode(Node* theNode, int f){
        theNode->frq = f;
        minFreq = minFreq > f ? f : minFreq;
        Node* head;
        if(freq_mpp.find(f) != freq_mpp.end())head = freq_mpp[f].first;
        else{
            head = new Node(-1, -1);
            Node* tail = new Node(-1, -1);
            head->next = tail;
            tail->prev = head;
            freq_mpp[f] = {head, tail};
        }

        Node* theFirst = head->next;

        head->next = theNode;
        theNode->next = theFirst;
        theFirst->prev = theNode;
        theNode->prev = head;

        dict[theNode->key] = theNode;
        return;
    }
    
    void removeNode(Node*theNode){
        int f = theNode->frq;
        Node* thePrev = theNode->prev;
        Node* theNext = theNode->next;
        
        thePrev->next = theNext;
        theNext->prev = thePrev;

        Node* head = freq_mpp[f].first;
        Node* tail = freq_mpp[f].second;
        if(head->next == tail){
            freq_mpp.erase(f);
            if(minFreq == f)minFreq++;
        }
        dict.erase(theNode->key);
        delete theNode;
    }

    int get(int key) {
        if(dict.find(key) != dict.end()){
            int a_frq = dict[key]->frq;
            int a_val = dict[key]->value;
            removeNode(dict[key]);
            Node* theNode = new Node(key, a_val);
            addNode(theNode,a_frq+1);
            return dict[key]->value;
        }
        return -1;
        
    }
    
    void put(int key, int value) {
        if(dict.find(key) != dict.end()){
            int a_frq = dict[key]->frq;
            removeNode(dict[key]);
            Node* theNode = new Node(key, value);
            addNode(theNode,a_frq+1);
            return;
        }
        if(dict.size()>=cap){
            Node* theNode = freq_mpp[minFreq].second->prev;
            removeNode(theNode);
            
        }
        Node* tmp = new Node(key, value);
        addNode(tmp,1);
        return;
    }
};

int main(){
    LFUCache* a = new LFUCache(2);
    a->put(1,1);
    a->put(2,2);
    a->get(1);
    a->put(3,3);
    a->get(2);
    a->get(3);
    a->put(4,4);
    a->get(1);
    a->get(3);
    a->get(4);
    return;
}