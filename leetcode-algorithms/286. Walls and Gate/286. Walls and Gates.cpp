#include<iostream>
#include<vector>
#include<queue>

using namespace std;

/*
class Solution {
public:
    void wallsAndGates(vector<vector<int> >& rooms) {
        int n = rooms.size();
        if(n == 0) return;
        int m = rooms[0].size();
        if(m == 0) return;
        
        for(int i=0; i<n; i++){
        	for(int j=0; j<m;j++){
        		if(rooms[i][j] == 0) dfs(rooms, i, j, 0);
			}
		}
    }
    
    void dfs(vector<vector<int> > &rooms, int i, int j, int d){
    	int n= rooms.size();
    	int m= rooms[0].size();
    	if(i<0 || j<0 ||i>=n || j>=m || rooms[i][j] < 0 || rooms[i][j] < d) return;
    	rooms[i][j] = d;
    	d = d +1;
    	dfs(rooms, i+1, j, d);
    	dfs(rooms, i, j+1, d);
    	dfs(rooms, i-1, j, d);
    	dfs(rooms, i, j-1, d);
	}
};
*/


class Solution {
public:
    void wallsAndGates(vector<vector<int> >& rooms) {
        int n = rooms.size();
        if(n == 0) return;
        int m = rooms[0].size();
        if(m == 0) return;
        queue<pair<int, int> > q;
        
        for(int i=0; i<n; i++){
        	for(int j=0; j<m; j++){
        		if(rooms[i][j] == 0) q.push(make_pair(i,j));
			}
		}
		
		while(!q.empty()){
			pair<int, int> p = q.front();
			q.pop();
			if(p.first - 1 >= 0){
				if(rooms[p.first-1][p.second] == 2147483647){
					rooms[p.first-1][p.second] = rooms[p.first][p.second] + 1;
					q.push(make_pair(p.first-1, p.second));
				}
			}
			
			if(p.first + 1 < n){
				if(rooms[p.first+1][p.second] == 2147483647){
					rooms[p.first+1][p.second] = rooms[p.first][p.second] + 1;
					q.push(make_pair(p.first+1, p.second));
				}
			}
			
			if(p.second - 1 >= 0){
				if(rooms[p.first][p.second-1] == 2147483647){
					rooms[p.first][p.second-1] = rooms[p.first][p.second] + 1;
					q.push(make_pair(p.first, p.second-1));
				}
			}
			if(p.second + 1 < m){
				if(rooms[p.first][p.second+1] == 2147483647){
					rooms[p.first][p.second+1] = rooms[p.first][p.second] + 1;
					q.push(make_pair(p.first, p.second+1));
				}
			}	
		} 
    }
};



int main(){
}
