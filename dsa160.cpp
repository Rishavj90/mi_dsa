#include <bits/stdc++.h>
using namespace std;

class MyStack{
    private:
    int arr[1000];
    int top;

    public:
    MyStack(){top=-1;}
    int pop();
    void push(int);
};

void MyStack ::push(int x) {
    top = (top+1)%1000;
    arr[top] = x;
    return;
}

int MyStack ::pop() {
    if(top == -1)return -1;
    int out = arr[top];
    top--;
    return out;
}

int main(){
    vector<int>vec = {1, 2, 1, 3, 2, 1, 4, 2};
    MyStack mstk;
    int i = 0;
    while(i < vec.size()){
        if(vec[i]==1){
            mstk.push(vec[i+1]);
            i+=2;
        }else {
            cout << mstk.pop() << " ";
            i++;
        }
    }
    return 0;
}