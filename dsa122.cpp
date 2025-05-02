#include <bits/stdc++.h>
using namespace std;

class SortedStack{
    public:
    stack<int> s;
    void sort();
};

void insert_in_sorted_stack(stack<int>&s, int num){
    if(s.empty() || s.top() <= num){
        s.push(num);
        return;
    }
    int a = s.top();
    s.pop();
    insert_in_sorted_stack(s, num);
    s.push(a);
}

void SortedStack :: sort(){
    if(s.empty()) return;
    int num = s.top();
    s.pop();
    sort();
    insert_in_sorted_stack(s, num);
}

int main(){
    vector<int> vec = {8,4,16,11,7,19};
    SortedStack stack_obj;
    for(int i = 0; i < vec.size(); i++){
        stack_obj.s.push(vec[i]);
    }
    stack_obj.sort();
    while(!stack_obj.s.empty()){
        cout << stack_obj.s.top() << " ";
        stack_obj.s.pop();
    }
    return 0;
}
