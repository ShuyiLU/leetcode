#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    int assignBikes(vector<vector<int> >& workers, vector<vector<int> >& bikes) {
        return dp(0, 0, workers, bikes);
    }
    
    int getMahattan(vector<int> p1, vector<int> p2){
    	return abs(p1[0]-p2[0]) + abs(p1[1]-p2[1]);
	}
	
	int dp(int cur_w, int cur_b, const vector<vector<int> >& workers, const vector<vector<int> >& bikes)
	{
		if(cur_w >= workers.size()) return 0;
		auto it = mp.find(cur_w + bike)
		
	}
	
	unordered_map<int, int> mp;
	
	
};
