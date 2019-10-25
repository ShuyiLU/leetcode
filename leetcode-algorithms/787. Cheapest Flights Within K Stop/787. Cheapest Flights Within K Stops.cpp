#include<iostream> 
#include<vector>
#include<queue>

using namespace std;

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int> >& flights, int src, int dst, int K) {
        vector<vector<int> > graph(n, vector<int>(n, -1));
        for(int i=0; i<flights.size(); i++) graph[flights[i][0]][flights[i][1]] = flights[i][2];
        int res = INT_MAX;
        int step = 0;
        queue<pair<int, int> > q; //(src, cost)
        q.push(make_pair(src, 0));
        int flag
        while(!q.empty()){
        	for(int i=0; i<q.size(); i++){
	         	pair<int, int> f = q.front();
	        	q.pop();
	        	flag = 0;
	        	int cur = f.first;
	        	int cost = f.second;   //total cost to cur  
				if(cur == dst) res = min(res, cost);  
				for(int j=0; j<n; j++){
					if(graph[cur][j] >= 0) {
						if(cost + graph[cur][j] > res) continue;
						q.push(make_pair(j, cost+graph[cur][j]));						
					}
				}				
			}
			if(step > K) break;
			step  += 1;	
		}
		if(res == INT_MAX) return -1;
		return res;
		
    }
};
