#include <bits/stdc++.h>
using namespace std;

class MyQueue {
    public:
    stack<int> stk_1;
    stack<int> stk_2;

    MyQueue(){}

    void push(int x) {
        stk_1.push(x);
    }

    int pop() {
        if(stk_2.empty()){
            while(!stk_1.empty()){
                stk_2.push(stk_1.top());
                stk_1.pop();
            }
        }
        int out = stk_2.top();
        stk_2.pop();
        return out;
    }

    int peek() {
        if(stk_2.empty()){
            while(!stk_1.empty()){
                stk_2.push(stk_1.top());
                stk_1.pop();
            }
        }
        return stk_2.top();
    }

    bool empty() {
        if(stk_1.empty() && stk_2.empty())return true;
        return false;
    }
};