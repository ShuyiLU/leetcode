#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

bool cmp(vector<int> &v1, vector<int> &v2){
	return v1[0] < v2[0];
}

class Solution {
public:
    int videoStitching(vector<vector<int> >& clips, int T) {
        sort(clips.begin(), clips.end(), cmp);
        vector<int> dp(T+1, INT_MAX-1);  
        dp[0] = 0;
        for(int i=0; i<clips.size(); i++){
        	int end = clips[i][1];
        	if(end > T) end = T;
        	for(int j=clips[i][0]; j<end; j++){
        		dp[end] = min(dp[end], dp[j]+1);
			}
		}
		if(dp[T] == INT_MAX-1) return -1;
		return dp[T];
    }
};

class Solution {
public:
    int videoStitching(vector<vector<int> >& clips, int T) {
        sort(clips.begin(), clips.end(), cmp);
        int right=0, res=0, maxRight=0;
        for(int i=0; i<clips.size(); i++){
        	if(clips[i][0] <= right){
        		maxRight = max(maxRight, clips[i][1]);
			}
			else{
				if(right == maxRight) return -1;
				right = maxRight;
				res++;
				i--;
			}
			if(right >= T) return res;
		}
		if(maxRight >= T) return res+1;
		return -1;
    }
};
