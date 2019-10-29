#include<iostream>
#include<cstring>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        int n = timePoints.size();
        int res = 24*60;
        int dif;
        sort(timePoints.begin(), timePoints.end());
        for(int i=0; i<n-1; i++){
        	dif = timediff(timePoints[i], timePoints[i+1]);
        	dif = min(dif, 24*60-dif);
        	res = min(res, dif);
		}
		dif = timediff(timePoints[0], timePoints[n-1]);
		dif = min(dif, 24*60-dif);
        res = min(res, dif);
		
        return res; 
        
    }
    
    int timediff(string s1, string s2){
    	int h1 = stoi(s1.substr(0, 2)); //subtstr(begin, len)
    	int m1 = stoi(s1.substr(3, 2));
    	int h2 = stoi(s2.substr(0, 2)); //subtstr(begin, len)
    	int m2 = stoi(s2.substr(3, 2));
    	int res = abs((h1-h2)*60 + (m1-m2));
    	return res;
	}
    
};
