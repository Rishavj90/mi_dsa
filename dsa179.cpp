#include <bits/stdc++.h>
using namespace std;

vector<int> asteroidCollision(vector<int>& asteroids) {
    stack<int>stk;
    for(int i = 0; i < asteroids.size(); i++){
        if(asteroids[i] <0){
            int temp = -1*asteroids[i];
            while(!stk.empty() 
                    && stk.top() > 0
                    && temp > stk.top())stk.pop();
            
            if(stk.empty() 
                || stk.top() < 0 
                || temp > stk.top())stk.push(asteroids[i]);
            else if(temp == stk.top())stk.pop();

        }else stk.push(asteroids[i]);
    }
    vector<int>vec;
    while(!stk.empty()){
        vec.push_back(stk.top());
        stk.pop();
    }
    reverse(vec.begin(), vec.end());
    return vec;
}

int main(){
    vector<int>asteroid = {5,-5};
    vector<int>ans = asteroidCollision(asteroid);
    for(auto i : ans)cout << i << " ";
    return 0;
}