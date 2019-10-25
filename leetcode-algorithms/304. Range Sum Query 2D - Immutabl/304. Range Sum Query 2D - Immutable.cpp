#include<iostream>
#include<vector>

using namespace std;

class NumMatrix {
public:
	vector<vector<int> > dp;
    NumMatrix(vector<vector<int> >& matrix) {
        if(matrix.size() == 0) return;
        else{
        	dp.resize(matrix.size());
			for(int i=0; i<matrix.size(); i++) dp[i].resize(matrix[i].size()); //dp[i][j] = sum(0,0,i,j)
        	dp[0][0] = matrix[0][0];
        	for(int i=1; i<matrix[0].size(); i++) dp[0][i] = dp[0][i-1]+matrix[0][i];
        	for(int i=1; i<matrix.size(); i++) dp[i][0] = dp[i-1][0]+matrix[i][0];
        	for(int i=1; i<matrix.size(); i++){
        		for(int j=1; j<matrix[0].size(); j++){
        			dp[i][j] = dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1] + matrix[i][j];
				}
			}
		}
    }
    
    int sumRegion(int r1, int c1, int r2, int c2) {
        int ans = dp[r2][c2];
        if(r1 != 0) ans = ans - dp[r1-1][c2];
        if(c1 != 0) ans = ans - dp[r2][c1-1];
        if(r1 != 0 && c1 != 0) ans = ans + dp[r1-1][c1-1];
        return ans;
    }
    
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */
