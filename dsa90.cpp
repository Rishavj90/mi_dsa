#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node(int a){
        data = a;
        next = nullptr;
    };
};

Node* constructLL(vector<int>& arr) {
    Node* head = new Node(arr[0]);
    Node* mover = head;
    for(int i = 1; i < arr.size(); i++){
        Node* temp = new Node(arr[i]);
        mover->next= temp;
        mover = temp;
    }
    return head;
}
int main(){
    vector<int> vec = {1,4,85,8};
    Node*head = constructLL(vec);
    Node* i = head;
    while(i != nullptr){
        cout << i->data << " ";
        i = i->next;
    }
    return 0;
}