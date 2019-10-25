#include<iostream>
#include<vector> 
#include<algorithm>

using namespace std;

class Solution {
public:
    int minPathSum(vector<vector<int> >& grid) {
    	int n = grid.size();
    	if(n == 0) return 0;
    	int m = grid[0].size();
    	if(m == 0) return 0;
    	
    	vector<vector<int> > f;
    	f.resize(n);
    	for(int i=0; i<n; i++) f[i].resize(m);
    	
    	//f[0][0] = grid[0][0];
    	for(int i=0; i<n; i++){
    		for(int j=0; j<m; j++){
    			if(i == 0 && j == 0) f[i][j] = grid[i][j];
    			else if(i-1<0) f[i][j] = grid[i][j] + f[i][j-1];
    			else if(j-1 <0) f[i][j] = grid[i][j] + f[i-1][j];
    			else f[i][j] = min(f[i-1][j], f[i][j-1]) + grid[i][j];
			}
		}
    	
    	return f[n-1][m-1];
        
    }
};


int main(){
	int n, m;
	//cin >> n >> m;
	
}
