#include<iostream>
#include<vector>
#include<queue>
#include<set>

using namespace std;

class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int> >& red, vector<vector<int> >& blue) {
        vector<vector<int> > edge;  //edges from ith point
        edge.resize(2*n);
        for(int i=0; i<red.size(); i++){
        	if(red[i][1]!=0) edge[red[i][0]].push_back(red[i][1] + n);
        	else edge[red[i][0]].push_back(red[i][1]);
		}
		for(int i=0; i<blue.size(); i++){
		    if(blue[i][0] != 0) edge[blue[i][0]+n].push_back( blue[i][1]);
		    else edge[blue[i][0]].push_back(blue[i][1]);
		}
		vector<int> ans(2*n, -1);
		set<int> s;
		ans[0] = 0;
		queue<pair<int, int> >q; //<point, dis>;
		q.push(make_pair(0,0));
		s.insert(0);
		while(!q.empty()){
			pair<int, int> tmp = q.front();
			int p = tmp.first;
			int dis = tmp.second;
			q.pop();
			for(int i=0; i<edge[p].size(); i++){
				if(s.count(edge[p][i]) == 0) {
					q.push(make_pair(edge[p][i], dis+1));
					ans[edge[p][i]] = dis+1;
					s.insert(edge[p][i]);	
				}
			}
		}
		for(int i=1; i<n; i++){
			if(ans[i] == -1 && ans[i+n] == -1) ans[i] = -1;
			else if(ans[i] == -1 && ans[i+n] > 0) ans[i] = ans[i+n];
			else if(ans[i]>0 && ans[i+n] == -1) ans[i] = ans[i];
			else if(ans[i]>0 && ans[i+n]>0) ans[i] = min(ans[i], ans[i+n]);
		}
		ans.resize(n);
		return ans;      
    }
}; 
