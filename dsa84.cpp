#include <bits/stdc++.h>
using namespace std;

int maxDepth(string s) {
    int n = 0, ans = INT_MIN;
    for(int i = 0; i < s.length(); i++){
        if(s[i] == '('){
            n++;
            if(n > ans){
                ans = n;
            }
        }else if(s[i] == ')'){
            n--;
        }
    }
    if(ans == INT_MIN){
        return 0;
    }
    return ans;
}
int main(){
    string a = "(1+(2*3)+((8)/4))+1";
    cout << maxDepth(a);
    return 0;
}