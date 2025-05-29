#include <bits/stdc++.h>
using namespace std;

bool part_s(int id, string s, vector<int> &str_hash, unordered_map<string,int>&hash_dict){
    if(id == s.length())return str_hash[id] = true; 
    for(int i = 1; i <= s.length()-id; ++i){
        string str = s.substr(id,i);
        if(hash_dict.find(str) != hash_dict.end() && 
           part_s(id+i,s,str_hash,hash_dict))return str_hash[id] = true;
        if(str_hash[id] != -1)return str_hash[id];
    }
    return str_hash[id] = false;
}

bool wordBreak(string s, vector<string>& wordDict) {
    vector<int>str_hash(s.length()+1,-1);
    unordered_map<string,int> hash_dict;
    for(auto i : wordDict){
        hash_dict[i]++;
    }
    return part_s(0,s,str_hash,hash_dict);
}

int main(){
    string s = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaab";
    vector<string> wordDic = {"a", "aa", "aaa", "aaaa"};
    cout << true << " : true " << false << " : false" << endl;
    cout << wordBreak(s,wordDic);
    return 0;
}