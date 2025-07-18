#include <bits/stdc++.h>
using namespace std;

string minWindow(string& s1, string& s2) {
	int j = 0; //for s2
	int start = -1;
	int minLen = s1.length();
	for(int i = 0; i < s1.length(); i++){
		if(s1[i] == s2[j])j++;
		if(j == s2.length()){
			int end = i;
			j--;
			while(j >= 0){
				if(s1[i] == s2[j])j--;
				i--;
			}
			int st = i+1;
			j++;
			int currLen = end - st + 1;
			if(currLen < minLen){
				start = st;
				minLen = currLen;
			}
			i = st;
		}
	}
	string ans;
	if(start != -1)ans = s1.substr(start, minLen);
	return ans;
}

int main(){
	string s1 = "geeksforgeeks";
	string s2= "eksrg";
	cout << minWindow(s1, s2);
	return 0;
}