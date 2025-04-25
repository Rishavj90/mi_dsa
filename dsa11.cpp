#include <bits/stdc++.h>
using namespace std;

string input(string str1){
    string str2;
    for(int i = 0; i < str1.size(); ++i){
        if(str1[i] >= 'a' && str1[i] <= 'z') str2.push_back(str1[i]);
        else if (str1[i] >= 'A' && str1[i] <= 'Z') str2.push_back(str1[i]+32);
    }
    return str2;
}

int i = 0;
bool isPalindrome(string str1){
    string str2 = input(str1);
    int a = str2.size();
    if (a==0) return true;
    if(str2[i] != str2[a-1-i]){
        return false;
    }
    if(i == a/2) return true;
    i++;
    return isPalindrome(str2);
}

int main(){
    string str;
    cin >> str;
    cout << isPalindrome(str);
    return 0;
}