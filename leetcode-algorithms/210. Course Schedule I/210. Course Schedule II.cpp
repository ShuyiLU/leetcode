#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int> >& prerequisites) {
        vector<vector<int> > adj(numCourses, vector<int>{});
        vector<int> indegree(numCourses, 0);
        for(int i=0; i<prerequisites.size(); i++){
        	adj[prerequisites[i][0]].push_back(prerequisites[i][1]);
        	indegree[prerequisites[i][1]] ++;
		}
		vector<int> res;
		queue<int> q;
		for(int i=0; i<numCourses; i++){
			if(indegree[i] == 0) q.push(i);
		}
		while(!q.empty()){
			int tmp = q.front();
			res.push_back(tmp);
			q.pop();
			for(int i=0; i<adj[tmp].size(); i++){
				indegree[adj[tmp][i]]--;
				if(indegree[adj[tmp][i]] == 0){
					q.push(adj[tmp][i]);
				}
			}
		}
		return res;
		
    }
};
