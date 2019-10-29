#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    vector<vector<int> > allPathsSourceTarget(vector<vector<int> >& graph) {
    	vector<vector<int> > res;
    	vector<int> path;
    	path.push_back(0);
        dfs(res, graph, 0, graph.size()-1, path);
        return res;
    }
    
    void dfs(vector<vector<int> > & res, vector<vector<int> >& graph, int cur, int end, vector<int> &path){
    	if(cur == end){
    		res.push_back(path);
    		return;
		}
		
		for(int i=0; i<graph[cur].size(); i++){
			path.push_back(graph[cur][i]);
			dfs(res, graph, graph[cur][i], end, path);
			path.pop_back();
		}	
	}
};
