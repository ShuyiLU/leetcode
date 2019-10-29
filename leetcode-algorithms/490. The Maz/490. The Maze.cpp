#include<iostream>
#include<vector>
#include<queue>

using namespace std;

class Solution {
public:
    bool hasPath(vector<vector<int> >& maze, vector<int>& start, vector<int>& destination) {
        int n = maze.size();
        int m = maze[0].size();
        vector<vector<int> > visited(n, vector<int>(m, 0) );
        queue<pair<int, int> >q;
        q.push(make_pair(start[0], start[1]));
        visited[start[0]][start[1]] = 1;
        while(!q.empty()){
        	pair<int, int> p = q.front();
        //	cout << p.first << " " << p.second << endl;
        	q.pop();
        	if(p.first == destination[0] && p.second == destination[1]) return true;
        //	if(visited[p.first][p.second] == 1) continue;
        	
        	for(int i=0; i<4; i++){
        		int x = p.first, y = p.second;
        		while(x>=0 && y>=0 && x<n && y<m){
        			if(i == 0){
        				if(x-1 < 0 || maze[x-1][y] == 1){
        					if(visited[x][y] == 0){
                            	q.push(make_pair(x, y));
        						visited[x][y] = 1;
                            //	cout << "up: " << x << " " << y <<endl;
        					}
                            break;
                            
						}
						else x = x-1;
					}
					
					else if(i == 1){
        				if(x+1 >= n || maze[x+1][y] == 1){
                            if(visited[x][y] == 0){
	        					q.push(make_pair(x, y));
	        					visited[x][y] = 1;
	                         //   cout << "down: " << x << " " << y <<endl;
        					}
                            break;
                            
						}
						else x = x+1;
					}
					
					else if(i == 2){
        				if(y-1 < 0 || maze[x][y-1] == 1){
                            if(visited[x][y] == 0){
	        					q.push(make_pair(x, y));
	        					visited[x][y] = 1;
	                          //  cout << "left: " << x << " " << y <<endl;
        					}
                            break;
                            
						}
						else y = y-1;
					}
					
					else if(i == 3){
        				if(y+1 >= m || maze[x][y+1] == 1){
                            if(visited[x][y] == 0){
	        					q.push(make_pair(x, y));
	        					visited[x][y] = 1;
	                          //  cout << "right: " << x << " " << y <<endl;
                            }
                            break;
                            
						}
						else y = y+1;
					}
					
					
				}
			}
			
		}
		return false;
    }
    
    
    
};

int main(){
	int n, m;
	cin >> n >> m;
	vector<vector<int> > maze(n, vector<int>(m, 0));
	int a;
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			cin >>a;
			maze[i][j] = a;	
		}
	}
	
	vector<int> s;
	vector<int> d;
	int c, e;
	for(int i=0; i<2; i++){
		cin >> c;
		s.push_back(c);
	}
	for(int i=0; i<2; i++){
		cin >> e;
		d.push_back(e);
	}
	Solution sol;
	if(sol.hasPath(maze, s, d)) cout << "true" << endl;
	else cout << "false" << endl;
}
