#include<iostream>
#include<vector>
#include<map>

using namespace std;

class Solution {
public:
    bool carPooling(vector<vector<int> >& trips, int capacity) {
        map<int, vector<int> > mp;
        
        for(int i=0; i<trips.size(); i++){
        	mp[trips[i][1]].push_back(trips[i][0]);
        	mp[trips[i][2]].push_back(-1 * trips[i][0]);
		}
		
		int cnt = 0;
		map<int, vector<int> > :: iterator it;
		for(it=mp.begin(); it!=mp.end(); it++){
			for(int i=0; i<(*it).second.size(); i++){
				cnt += (*it).second[i];
			}
			if(cnt > capacity) return false;
		}
		return true;
    }
};
