#include <bits/stdc++.h>
using namespace std;

int main(){
    int x;
    cin >> x;

    string s = to_string(x); 
    int size = s.size()/2;
    int flag = 1;
    for(int i =0; i < size; ++i){
        if(s[i]==s[s.size()-1-i]){
            flag =1;
        }else{
            flag =0;
            break;
        }
    }

    if(flag == 1){
        cout << "true";
    }else{
        cout << "false";
    }

    return 0;
}