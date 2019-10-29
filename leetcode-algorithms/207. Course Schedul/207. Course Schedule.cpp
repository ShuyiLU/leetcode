#include<iostream>
#include<vector>

using namespace std; 


class Solution {
public:
    bool canFinish(int n, vector<pair<int, int> >& pre) {
        if(n == 0) return true;
        if(pre.size() == 0) return true;
        
        //map<int, int> in_de; //(point, indegree)
        //in_de.resize(n, 0)
        vector<int> degree(n,0); // record point's indegree, index[i] means point i;
        vector< vector<int> > v;
        v.resize(n);
        if(!v.empty()) v.clear();
        for(int i=0; i<pre.size(); i++){
        	v[pre[i].first].push_back(pre[i].second);
        	degree[pre[i].second]++;
		}
		//int flag = 0;
		int k=0;
		while(k<n){
			if(degree[k] == 0){
				degree[k] = -1;
				for(int j=0; j<v[k].size(); j++){
					degree[v[k][j]]--;
				}
				k = 0;
			}
			else{
				k++;
			}			
		}
		for(int i=0; i<degree.size(); i++){
			if(degree[i] != -1) return false;
		}
		return true;
    }
};

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& p) {
        queue<int> q;
        vector<int> v;
        int n = p.size();
        vector<int> inDegree(n, 0);
        vector<list<int>> adj(n, list<int>{});
        
        if(n == 0) return true;
        for(int i=0; i<n; i++){
            adj[p[i][0]].push_back(p[i][1]);
            inDegree[p[i][1]]++;
        }
        for(int i=0; i<n; i++){
            if(inDegree[i] == 0) q.push(i);
        }
        while(!q.empty()){
            int k = q.front();
            q.pop();
            v.push_back(k);
            list<int> :: iterator it;
            for(it=adj[k].front(); it!=adj[k].end(); it++){
                inDegrees[*it]--;
                if(inDegrees[*it] == 0) q.push(*it);
            }
        }
        if(v.size() != n) return false;
        return true;
    }
};


class Solution {
public:
    bool canFinish(int n, vector<pair<int, int> >& pre) {
        
    }
};

int main(){
}
