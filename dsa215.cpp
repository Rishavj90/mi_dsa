#include <bits/stdc++.h>
using namespace std;

class MedianFinder {
    priority_queue<int>left_max;
    priority_queue<int,vector<int>,greater<int>>right_min;
public:
    MedianFinder(){}
    
    void addNum(int num) {
        if(left_max.empty() || num < left_max.top())left_max.push(num);
        else right_min.push(num);

        if(left_max.size() < right_min.size()){
            int a = right_min.top();
            right_min.pop();
            left_max.push(a);
        }

        if(left_max.size() - right_min.size() >1){
            int a = left_max.top();
            left_max.pop();
            right_min.push(a);
        }
    }
    
    double findMedian() {
        if(left_max.size() == right_min.size()){
            double ans = (double)(left_max.top()+right_min.top())/2;
            return ans; 
        }
        return (double)left_max.top();
    }
};

int main(){
    MedianFinder* obj = new MedianFinder();
    obj->addNum(-1);
    cout << obj->findMedian() << "\n";
    obj->addNum(-2);
    cout << obj->findMedian() << "\n"; 
    obj->addNum(-3);
    cout << obj->findMedian() << "\n";
    obj->addNum(-4);
    cout << obj->findMedian() << "\n";
    obj->addNum(-5);
    cout << obj->findMedian() << "\n";
    return 0;
}