#include <bits/stdc++.h>
using namespace std;

void insert(stack<int> &s, int n){
    if(s.empty()){
        s.push(n);
        return;
    }
    int num = s.top();
    s.pop();
    insert(s, n);
    s.push(num);
}

void Reverse(stack<int> &St) {
    if(St.empty()) return;
    int num = St.top();
    St.pop();
    Reverse(St);
    insert(St, num);
}

int main(){
    vector<int> vec = {8,4,16,11,7,19};
    stack<int> stack_obj;
    for(int i = 0; i < vec.size(); i++){
        stack_obj.push(vec[i]);
    }
    Reverse(stack_obj);
    while(!stack_obj.empty()){
        cout << stack_obj.top() << " ";
        stack_obj.pop();
    }
    return 0;
}