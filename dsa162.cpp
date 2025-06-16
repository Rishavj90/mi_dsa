#include <bits/stdc++.h>
using namespace std;

struct QueueNode{
    int data;
    QueueNode *next;
    QueueNode(int a)
    {
        data = a;
        next = NULL;
    }
};

struct MyQueue {
    QueueNode *front;
    QueueNode *rear;
    void push(int);
    int pop();
    MyQueue() {front = rear = NULL;}
};

void MyQueue:: push(int x){
    QueueNode* temp = new QueueNode(x);
    if(front == NULL)front = temp; 
    else rear->next = temp;
    rear = temp;
    return; 
}

int MyQueue :: pop(){
    if(front == NULL)return -1;
    int out = front->data;
    QueueNode* del_node = front;
    front = front->next;
    delete del_node;
    return out;
}