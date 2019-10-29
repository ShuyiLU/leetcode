#include<iostream>
#include<cstring>
#include<vector>

using namespace std;

class Solution {
public:
    int maxKilledEnemies(vector<vector<char>>& grid) {
        int n = grid.size();
        if(n == 0) return 0;
        int m = grid[0].size();
        int row=0, res = 0;
        vector<int> col(m, 0);
        for(int i=0; i<n; i++){
        	for(int j=0; j<m; j++){
        		if(j == 0 || grid[i][j-1] == 'W'){ //从墙的下方开始遍历，当前列还有多少e 
        			rows = 0;
        			for(int k=j; k<m; k++){
        				if(grid[i][k] == 'W') break;
        				if(grid[i][k] == 'E') rows += 1;
					}
				}
				
				if(i == 0 || grid[i-1][j] == 'W'){ //从墙的右边开始遍历 ，当前行还有多少e 
					cols[j] = 0;
					for(int k=i; k<n; k++){
						if(grid[k][j] == 'W') break;
						if(grid[k][j] == 'E') cols[j] += 1;
					}
				} 
				
				if(grid[i][j] == '0') res = max(rows + col[j], res); //已更新的行列各自的e或者前面算好的行和列的e之和 
				
			}
			return res;
		}
    }
};
