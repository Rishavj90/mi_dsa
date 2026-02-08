#include <bits/stdc++.h>
using namespace std;

unordered_map<char, unordered_set<char>> adjList(vector<string> &words){
    unordered_map<char, unordered_set<char>>adj;
    for(const auto& word : words){
        for(char i : word){
            adj[i];
        }
    }

    for(int i=0; i<words.size()-1; i++){
        int k=0;
        while(
            k<words[i].size() && 
            k<words[i+1].size() && 
            words[i][k] == words[i+1][k]
        )k++;

        if(k<words[i].size() && k<words[i+1].size()){
            adj[words[i][k]].insert(words[i+1][k]);
        }else if(k<words[i].size() && k>=words[i+1].size()){
            return unordered_map<char, unordered_set<char>>();
        }
    }
    return adj;
}

string findOrder(vector<string> &words) {
    unordered_map<char, unordered_set<char>>adj=adjList(words);
    if(adj.empty())return "";
    int n = adj.size(); 

    unordered_map<char, int>Indegree;
    for(auto [a,b] : adj)Indegree[a]=0;
    for(auto [a,b] : adj){
        for(auto i : b){
            Indegree[i]++;
        }
    }

    string ans = "";
    queue<char>q;
    for(auto [a,b] : Indegree){
        if(b==0)q.push(a);
    }
    while(!q.empty()){
        char ch = q.front();
        q.pop();
        ans += ch;

        for(auto i : adj[ch]){
            Indegree[i]--;
            if(Indegree[i] == 0)q.push(i);
        }
    }
    if(ans.size() != n)return "";
    return ans;
}

