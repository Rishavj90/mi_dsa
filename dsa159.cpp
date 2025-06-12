#include <bits/stdc++.h>
using namespace std;

class MyQueue {
private:
    int arr[100005];
    int front;
    int rear;

public :
    MyQueue(){front=0;rear=0;}
    void push(int);
    int pop();
};

void MyQueue ::push(int x) {
    rear = (rear+1)%100005;
    arr[rear] = x;
    return;
}

int MyQueue ::pop() {
    if(rear-front <= 0)return -1;
    front = (front+1)%100005;
    int out = arr[front];
    return out;
}

int main(){
    vector<int>vec = {1,2,1,4,2,1,6,2,1,7,2,2,2,2};
    MyQueue qu;
    int n = vec.size();
    int i = 0;
    while(i < n){
        if(vec[i] == 1){
            qu.push(vec[i+1]);
            i+=2;
        }
        else{
            cout << qu.pop();
            i++;
        }
    }
    return 0;
}