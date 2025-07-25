#include <bits/stdc++.h>
using namespace std;

class Twitter {
    unordered_map<int,unordered_set<int>>following;
    unordered_map<int,vector<pair<int,int>>>tweets;  //{user, {time, post}}
    int start;

public:
    Twitter(){
        start = 0;
    }
    
    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({start,tweetId});
        ++start;
    }
    
    vector<int> getNewsFeed(int userId) {
        priority_queue<pair<int,int>>pq;
        for(auto i : tweets[userId])pq.push(i);
        for(auto a : following[userId]){
            for(auto i : tweets[a])pq.push(i);
        }
        vector<int>ans;
        while(!pq.empty()){
            auto i = pq.top();
            ans.push_back(i.second);
            pq.pop();
            if(ans.size() >= 10)break;
        }
        return ans;
    }
    
    void follow(int followerId, int followeeId) {
        following[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        following[followerId].erase(followeeId);
    }
};
