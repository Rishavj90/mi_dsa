#include <bits/stdc++.h>
using namespace std;

class Solution {
vector<int>rank, parent;

int pathCompression(int a){
    if(parent[a]==a)return a;
    return parent[a]=pathCompression(parent[a]);
}

int unionByRank(int a, int b) {
    int parentA = pathCompression(a), parentB = pathCompression(b);
    if(parentA == parentB)return 1;

    if(rank[parentA] == rank[parentB]){
        rank[parentA]++;
        parent[parentB]=parentA;

    }else if(rank[parentA] < rank[parentB]){
        parent[parentA]=parentB;
    }else{
        parent[parentB]=parentA;
    }
    return 0;
}

public:
vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
    int n=accounts.size();

    rank.resize(n,0);
    parent.resize(n,0);
    for(int i=0; i<n; i++)parent[i]=i;

    unordered_map<string, int>emailMap;
    for(int a=0; a<n; a++){
        for(int i=1; i<accounts[a].size(); i++){
            if(emailMap.find(accounts[a][i]) == emailMap.end())emailMap[accounts[a][i]]=a;
            else unionByRank(emailMap[accounts[a][i]], a);
        }
    }

    vector<vector<string>>emailAccounts;
    emailAccounts.resize(n);
    for(auto [email, user] : emailMap){
        int finalUser = pathCompression(user);
        emailAccounts[finalUser].push_back(email);
    }

    vector<vector<string>>ans;
    for(int i=0; i<n; i++){
        if(!emailAccounts[i].empty()){
            sort(emailAccounts[i].begin(), emailAccounts[i].end());
            vector<string>tmp;
            tmp.push_back(accounts[i][0]);
            tmp.insert(tmp.end(), emailAccounts[i].begin(), emailAccounts[i].end());
            ans.push_back(tmp);
        }
    }
    return ans;
}

};

