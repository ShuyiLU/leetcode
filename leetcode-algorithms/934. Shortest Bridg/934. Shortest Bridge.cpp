#include<iostream>
#include<vector>
#include<queue>

using namespace std;

class Solution {
public:
	int n, m;
	queue<pair<pair<int, int>, int> > q;
	vector<vector<int> > visited;
    int shortestBridge(vector<vector<int> >& A) {
        n = A.size();
        m = A[0].size();
        visited.resize(n, vector<int>(m, 0));
        int flag = 0;
        for(int i=0; i<n; i++){
			if(flag == 1) break;
        	for(int j=0; j<m; j++){
        		if(A[i][j] == 1) {
        			DFS(i, j, A);
                    flag = 1;
					break;	
				}  
			}
			
		}
		
		int res = INT_MAX;
		while(!q.empty()){
            
			int c_x = q.front().first.first;
			int c_y = q.front().first.second;
			int step = q.front().second;
            cout << c_x << " " << c_y << " " << step << endl;
			q.pop();
			if(c_x+1 < n && A[c_x+1][c_y] == 0 && visited[c_x+1][c_y] == 0){
				q.push(make_pair(make_pair(c_x+1, c_y), step+1));
				visited[c_x+1][c_y] = 1;
			}
			if(c_y+1 < m &&A[c_x][c_y+1] == 0 && visited[c_x][c_y+1] == 0){
				q.push(make_pair(make_pair(c_x, c_y+1), step+1));
				visited[c_x][c_y+1] = 1;
			}
			if(c_x-1 >= 0 && A[c_x-1][c_y] == 0 && visited[c_x-1][c_y] == 0){
				q.push(make_pair(make_pair(c_x-1, c_y), step+1));
				visited[c_x-1][c_y] = 1;
			}
			if(c_y-1 >= 0 &&A[c_x][c_y-1] == 0 && visited[c_x][c_y-1] == 0){
				q.push(make_pair(make_pair(c_x, c_y-1), step+1));
				visited[c_x][c_y-1] = 1;
			}
			
			if(c_x+1 < n &&A[c_x+1][c_y] == 1 && visited[c_x+1][c_y] == 0){
				res = min(res, step);
				break;
			}
			if(c_y+1 < m &&A[c_x][c_y+1] == 1 && visited[c_x][c_y+1] == 0){
				res = min(res, step);
				break;
			}
			
			if(c_x-1 >= 0 && A[c_x-1][c_y] == 1 && visited[c_x-1][c_y] == 0){
				res = min(res, step);
				break;
			}
			if(c_y-1 >= 0 &&A[c_x][c_y-1] == 1 && visited[c_x][c_y-1] == 0){
				res = min(res, step);
				break;
			}
			
		}
		
		return res;
    }
    
    void DFS(int i, int j, vector<vector<int> >& A){
    	if(i<0 || j<0 || i>= n || j>=m || A[i][j] == 0 || A[i][j] == 2) return;
    	A[i][j] = 2;
    	visited[i][j] = 1; 
    	q.push(make_pair(make_pair(i, j), 0));
    	DFS(i+1, j, A);
    	DFS(i-1, j, A);
    	DFS(i, j+1, A);
    	DFS(i, j-1, A);
	}
    
};
