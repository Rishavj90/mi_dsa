#include <bits/stdc++.h>
using namespace std;

class MinStack {
    stack<long long> stk;
    long long min;

    public:
    MinStack(){}
    
    void push(int val){
        if(stk.empty()){
            min = val;
            stk.push(val);
        }else{
            if(val <= min){
                stk.push((val *(long long)2) - min);
                min = val;
            }else{
                stk.push(val);
            }
        }
    }
    
    void pop(){
        if(stk.top() < min){
            min = (min *(long long)2) - stk.top();
        }
        stk.pop();
    }
    
    int top(){
        if(stk.top() <= min)return min;
        return stk.top();
    }
    
    int getMin(){
        return min;
    }
};

int main(){
    MinStack minStk;
    minStk.push(2147483646);
    minStk.push(2147483646);
    minStk.push(2147483647);
    minStk.top();
    minStk.pop();
    minStk.getMin();
    minStk.pop();
    minStk.getMin();
    minStk.pop();
    minStk.push(2147483647);
    minStk.top();
    minStk.getMin();
    minStk.push(-2147483648);
    minStk.top();
    minStk.getMin();
    minStk.pop();
    minStk.getMin();
    return 0;
}
