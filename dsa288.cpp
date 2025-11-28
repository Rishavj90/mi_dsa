#include <bits/stdc++.h>
using namespace std;

vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
    unordered_set<string>set(wordList.begin(), wordList.end());
    if(set.find(endWord) == set.end())return {};
    unordered_map<string, int>mpp;

    vector<vector<string>>ans;
    queue<pair<string, int>>q;
    q.push({beginWord, 1});
    mpp[beginWord] = 1;
    set.erase(beginWord);

    
    while(!q.empty()){
        string word = q.front().first;
        int step = q.front().second;
        q.pop();

        if(word == endWord)break;

        for(int i=0; i<beginWord.size(); ++i){
            char og = word[i];
            for(char a='a'; a<='z'; ++a){
                word[i] = a;
                if(set.find(word) != set.end()){
                    q.push({word, step+1});
                    mpp[word] = step+1;
                    set.erase(word);
                }
                word[i] = og;
            }
        }
    }

    vector<string>vec;
    vec.push_back(endWord);
    dfs(endWord, beginWord, mpp, vec, ans);
    return ans;
}

void dfs(string word, string beginWord, unordered_map<string, int>& mpp, vector<string>& vec, vector<vector<string>>& ans){
    
    if(word == beginWord){
        ans.push_back(vector<string>(vec.rbegin(), vec.rend()));
        return;
    }

    int step = mpp[word];
    for(int i=0; i<beginWord.size(); ++i){
        char og = word[i];
        for(char a='a'; a<='z'; a++){
            word[i] = a;
            if(mpp.find(word) != mpp.end() && mpp[word] == step-1){
                vec.push_back(word);
                dfs(word, beginWord, mpp, vec, ans);
                vec.pop_back();
            }
            word[i] = og;
        }
    }
}




