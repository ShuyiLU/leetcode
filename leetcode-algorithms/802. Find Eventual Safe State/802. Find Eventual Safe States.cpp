#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
		vector<int> color(n, 0);  //0: initial, 1: unsafe, 2:safe, 遇到1即该点也一定unsafe 
		vector<int> res;
		for(int i=0; i<n; i++){
			if(dfs(i, color, graph)) res.push_back(i);
		}
		return res;
    }
    
    bool dfs(int src, vector<int>&color, const vector<vector<int>>& graph){  //umsafe: false
    	if(color[src] == 1) return false;
		if(color[src] == 2) return true;
		color[src] = 1;
		for(int i=0; i<graph[src].size(); i++){
			if(dfs(graph[src][i], color, graph)==false || color[graph[src][i]] == 1) return false;
		} 
		color[src] = 2;
		return true;
	}
    
    
};
