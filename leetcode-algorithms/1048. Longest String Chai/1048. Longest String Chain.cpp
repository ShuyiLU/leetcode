#include<iostream>
#include<cstring>
#include<vector>

using namespace std;

bool cmp(string &a, string &b){
	return a.length() < b.length();
}

class Solution {
public:
    int longestStrChain(vector<string>& words) {
       // vector<int> dp(words.size(), 1);
        int cnt = 0;
        sort(words.begin(), words.end(), cmp);
        for(int i=1; i<words.size(); i++){
        	for(int k=0; k<i; k++){
        		if(isPre(words[k], words[i])) {
        			cnt++;
        		//	dp[i] = dp[i-1] + 1;
        			break;
				}
			}
			//dp[i] = max(dp[i-1], dp[i]);
		}
		return cnt;
    }
    
    bool isPre(string s1, string s2){
    	if(s2.length() != s1.length() + 1) return false;
    	int i=0, j=0;
    	for(j=0; j<s2.size(); j++){
    		if(s1[i] == s2[j]) i++;
    		j++;
		}
		if(i == s1.length()) return true;
		return false;
	}
	
};


class Solution {
public:
    int longestStrChain(vector<string>& words) {
        sort(words.begin(), words.end(), cmp);
        map<string, int> mp;  //mp[i] = j  加入i这个string作为chain的最大长度为j （i是chain当前最后一个） 
        int res=1;
        for(auto word : words){
        	mp[word] = 1;
        	for(int i=0; i<word.length(); i++){
        		string pre = word.substr(0, i) + word.substr(i+1);
				if(mp.count(pre) > 0){
					mp[word] = max(mp[word], mp[pre]+1);
					res = max(res, mp[word]);
				}
			}
		}
		return res;
    }
};
