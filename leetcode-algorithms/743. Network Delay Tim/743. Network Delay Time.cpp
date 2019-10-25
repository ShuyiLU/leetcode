#include<iostream>
#include<vector>
#include<algorithm>

using namespace std; 

class Solution {
public:
	void dijkstra(int k, int n, vector<vector<int> > &t, vector<int> &dis, vector<int> &path ){
		dis.resize(n+1);
		for(int i=0; i<n+1; i++) dis[i] = -1;
		path.resize(n+1);
		for(int i=0; i<n+1; i++) path[i] = -1;
		vector<bool> flag(n+1, 0);
		dis[k] = 0;
		while(1){
			int v = -1;
			for(int i=0; i<n+1; i++){
				if(flag[i] == 0 && dis[i] >= 0){
					if(v<0 || dis[i] < dis[v]) v = i;
				}
			}
			if(v<0) return;
			flag[v] = 1;
			for(int i=0; i<n+1; i++){
				if(t[v][i] >= 0){
					if(dis[i]<0 || dis[v]+t[v][i] < dis[i]){
						dis[i] = dis[v] + t[v][i];
						path[i] = v;
					}
					
				}
			}
		}
	}
	
	
    int networkDelayTime(vector<vector<int> >& times, int n, int K) {
        vector<vector<int> > t;
        t.resize(n+1);
        for(int i=0; i<n+1; i++) t[i].resize(n+1);
        for(int i=0; i<n+1; i++){
        	for(int j=0; j<n+1; j++){
        		t[i][j] = -1;
			}
		}
        for(int i=0; i<times.size(); i++){
        	t[times[i][0]][times[i][1]] = times[i][2];
		}
		vector<int> dis, path;
		dijkstra(K, n, t, dis, path);
		sort(dis.begin(), dis.end());
		if(dis[1] < 0) return -1;
		else return dis[n];
    }
};


void dijkstra(int begin, int n, vector<vector<int> > adj){
	vector<int> dis(n+1, -1);
	vector<int> path(n+1, -1);
	vector<bool> flag(n+1, 0);
	dis[begin] = 0;
	while(1){
		int v = -1;
		for(int i=0; i<=n; i++){
			if(flag[i]==0 && dis[i]>=0){ //未访问过的点且目前可达的点 
				if(v<0 || dis[i]<dis[v]) v=i;  //初始的点或者最小的可达点 
			}
		}
		if(v<0) return;
		flag[v] = 1;
		for(int i=0; i<=n; i++){
			if(adj[v][i] >= 0){   //可由v邻接到i 
				if(dis[i]<0 || dis[v]+adj[v][i] < dis[i]){  //更新距离 
					dis[i] = dis[v] + adj[v][i];
					path[i];
				}
			}
		}
	}
}

dis[i]:
for(int w=i; path[w] >0; w=path[w]) cout << w << "<-" << " ";



