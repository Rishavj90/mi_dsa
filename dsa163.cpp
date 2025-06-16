#include <bits/stdc++.h>
using namespace std;

class MyStack {
    queue<int> qu;

    public:
    MyStack(){}
    
    void push(int x) {
        qu.push(x);
        if(qu.size() > 1){
            int k = qu.size()-1;
            while(k--){
                qu.push(qu.front());
                qu.pop();
            }
        }
        return;
    }
    
    int pop() {
        if(qu.empty())return -1;
        int out = qu.front();
        qu.pop();
        return out;
    }
    
    int top() {
        return qu.front();
    }
    
    bool empty() {
        if(qu.empty())return true;
        return false;
    }
};
