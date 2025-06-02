#include <bits/stdc++.h>
using namespace std;

void make_str(int id, long curr, long prev, string str, string num, int target,vector<string>&ans){
    if(id == num.size()){
        if(curr == target)ans.push_back(str);
        return;
    }
    string s; long number = 0;
    for(int i = id; i <  num.length(); ++i){
        s += num[i];
        number = number*10 + num[i] - '0';
        
        //check leading zero
        if(s.length() > 1 && s[0] == '0')return;
        
        
        if(id == 0){
            make_str(i+1,number,number,s,num,target,ans);
        }else{
        make_str(i+1,curr+number,number,str+"+"+s,num,target,ans);
        make_str(i+1,curr-number,-number,str+"-"+s,num,target,ans);
        make_str(i+1,(curr - prev) + (prev*number),prev*number,str+"*"+s,num,target,ans);
        }
    }
    
}

vector<string> addOperators(string num, int target) {
    vector<string>ans;
    string str;
    make_str(0,0,0,str,num,target,ans);
    return ans;
}

int main(){
    string num = "123";
    vector<string> ans = addOperators(num, 6);
    for(auto i : ans)cout << i << endl;
    return 0;
}