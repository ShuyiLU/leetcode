#include<iostream>
#include<vector>

using namespace std;


class Solution {
public:
	int count = 0;
    int maxAreaOfIsland(vector<vector<int> >& grid) {
        if(grid.size() == 0) return 0;
        if(grid[0].size() == 0) return 0;
        int n = grid.size();
        int m = grid[0].size();
        int max = 0;
        for(int i=0; i<n; i++){
        	for(int j=0; j<m; j++){
        		if(grid[i][j] == 1) DFS(grid, i, j);
        		if(count > max) max = count;
        		count = 0;
			}
		}
		return max;
    }
    
    void DFS(vector<vector <int> >& grid, int i, int j){
    	int n = grid.size();
    	int m = grid[0].size();
    	if(i<0 || i>=n || j<0 || j>=m || grid[i][j] != 1) return;
    	grid[i][j] = 2;
    	count++;
    	DFS(grid, i+1, j);
    	DFS(grid, i-1, j);
    	DFS(grid, i, j+1);
    	DFS(grid, i, j-1);
	}
    
};

int main(){
}
