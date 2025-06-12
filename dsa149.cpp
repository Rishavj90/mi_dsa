#include <bits/stdc++.h>
using namespace std;

string decimal2Binary(int n){
    string str;
    while(n > 0){
        int b = n%2;
        char dig = '0'+b;
        str+= dig;
        n /= 2;    
    }
    reverse(str.begin(), str.end());
    return str;
}

int minBitFlips(int start, int goal) {
    long long s = start, g = goal, cnt = 0;
    while(s != 0 || g != 0){
        int s_bit = s & 1;
        int g_bit = g & 1;
        if(s_bit != g_bit)cnt++;
        s = s >>1;
        g = g >> 1;
    }
    return cnt;
}

int main(){
    int start = 10, goal = 7;
    cout << start << " : " << decimal2Binary(start) << " " << goal << " : " << decimal2Binary(goal) << endl;
    cout << minBitFlips(start, goal);
    return 0;
}