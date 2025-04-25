#include <bits/stdc++.h>
using namespace std;

bool rotateString(string s, string goal) {
    if(s.length() != goal.length()) return false;
    s = s + s;
    for(int i = 0; i< s.length(); i++){
        bool flg = true;
        for(int j = 0; j < goal.length(); j++){
            if(goal[j] != s[(i+j)%s.length()]){
                flg = false;
                break;
            }
        }
        if(flg == true) return true;
    }
    return false;
}
int main(){
    string a = "abcde";
    string b = "bcdea";
    cout << rotateString(a, b);
    return 0;
}