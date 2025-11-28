#include <bits/stdc++.h>
using namespace std;

/*
int bfs(int hasBeginWord, int hasEndWord, string beginWord, string endWord, vector<string>& wordList, vector<vector<int>>&adjList){
    int n = wordList.size(), m = beginWord.size();
    vector<int>visited(n, 0);
    queue<pair<int, int>>q;
    q.push({hasBeginWord, 1});
    while(!q.empty()){
        int index = q.front().first, len = q.front().second;
        q.pop();

        for(int i=0; i<adjList[index].size(); i++){
            int num = adjList[index][i];
            if(visited[num] == 0){
                if(num == hasEndWord)return len+1;
                q.push({num, len+1});
                visited[num] = 1;
            }
        }
    }
    return 0;
}

int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
    int n = wordList.size(), m = beginWord.size();
    int hasEndWord = -1, hasBeginWord = -1;
    for(int i=0; i<n; i++){
        int e_diff = 0, b_diff = 0;
        for(int k=0; k<m; k++){
            if(wordList[i][k] == beginWord[k])b_diff++;
            if(wordList[i][k] == endWord[k])e_diff++;
        }
        if(b_diff == m)hasBeginWord = i;
        if(e_diff == m)hasEndWord = i;
        if(hasBeginWord != -1 && hasEndWord != -1)break;
    }
    if(hasEndWord == -1)return 0;
    if(hasBeginWord == -1){
        wordList.push_back(beginWord);
        hasBeginWord = wordList.size()-1;
    }

    n = wordList.size();
    vector<vector<int>>adjList(n);
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(i==j)continue;
            int diff = 0;
            for(int k=0; k<m; k++){
                if(wordList[i][k] != wordList[j][k])diff++;
            }
            if(diff == 1)adjList[i].push_back(j);
        }
    }
    int ans = bfs(hasBeginWord, hasEndWord, beginWord, endWord, wordList, adjList);
    return ans;
}
*/


int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
    unordered_set<string>set(wordList.begin(), wordList.end());
    if(set.find(endWord) == set.end())return 0;
    
    queue<pair<string, int>>q;
    q.push({beginWord, 1});
    set.erase(beginWord);
    while(!q.empty()){
        string word = q.front().first;
        int step = q.front().second;
        q.pop();

        if(word == endWord)return step;

        for(int i=0; i<beginWord.size(); i++){
            char og = word[i];
            for(char j='a'; j<='z';j++){
                word[i] = j;
                if(set.find(word) != set.end()){
                    q.push({word, step+1});
                    set.erase(word);
                }
                word[i] = og;
            }
        }

    }
    return 0;
}


