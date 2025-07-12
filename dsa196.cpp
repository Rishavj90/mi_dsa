#include <bits/stdc++.h>
using namespace std;

int maxScore(vector<int>& cardPoints, int k) {
    int l = 0, r = cardPoints.size()-k-1;
    int sum = 0, maxscr = 0;
    for(int i =r+1; i < cardPoints.size(); i++)sum+=cardPoints[i];
    maxscr = sum;
    while(r < (cardPoints.size()-1)){
        sum= sum+cardPoints[l]-cardPoints[r+1];
        maxscr = (sum > maxscr) ? sum : maxscr;
        l++;
        r++;
    }
    return maxscr;
}

int main(){
    vector<int>cardpoints= {11,49,100,20,86,29,72};
    cout << maxScore(cardpoints,4);
    return 0;
}