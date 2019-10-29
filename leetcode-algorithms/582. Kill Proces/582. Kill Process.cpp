#include<iostream>
#include<vector>
#include<map>
#include<queue>
using namespace std;

class Solution {
public:
    vector<int> killProcess(vector<int>& pid, vector<int>& ppid, int kill) {
        map<int, vector<int> > mp;
        for(int i=0; i<ppid.size(); i++){
        	mp[ppid[i]].push_back(pid[i]);
		}
		
		queue<int> q;
		q.push(kill);
		
		vector<int> res;
		
		while(!q.empty()){
			int t = q.front();
			res.push_back(t);
			q.pop();
			for(int i=0; i<mp[t].size(); i++) q.push(mp[t][i]);
		}
		return res;
    }
};
