#include <bits/stdc++.h>
using namespace std;

class StackNode{
    public:
    int num;
    StackNode* next;
    StackNode(int n){
        num = n;
        next = nullptr;
    }
};

class MyStack {
  private:
    StackNode *top;
    int var_size = 0;

  public:
    void push(int x) {
        StackNode* temp = new StackNode(x);
        temp->next = top;
        top = temp;
        var_size++;
    }

    int pop() {
        if(var_size == 0)return -1;
        int out = top->num;
        top = top->next;
        return out;
    }

    MyStack() { top = NULL; }
};