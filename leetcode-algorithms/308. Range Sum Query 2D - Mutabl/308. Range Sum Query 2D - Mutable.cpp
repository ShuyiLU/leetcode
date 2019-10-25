#include<iostream>
#include<vector>

using namespace std;

class NumMatrix {
public:
	vector<vector<int> > sum;
	int n, m;
    NumMatrix(vector<vector<int> >& matrix) {
        n=matrix.size();
        if(n == 0) return;
        
        m = matrix[0].size();
        sum.resize(n);
        for(int i=0; i<n; i++) sum[i].resize(m);
        sum[0][0] = matrix[0][0];
        
        for(int i=1; i<n; i++) sum[i][0] = sum[i-1][0] + matrix[i][0];
        for(int i=1; i<m; i++) sum[0][i] = sum[0][i-1] + matrix[0][i];
        for(int i=1; i<n; i++){
        	for(int j=1; j<m; j++){
        		 sum[i][j] = sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1] + matrix[i][j];
			}
		}
		
		
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {			
        if(row1 == 0 && col1 == 0) return sum[row2][col2];
        else if(row1 == 0) return sum[row2][col2] - sum[row2][col1-1];
        else if(col1 == 0) return sum[row2][col2] - sum[row1-1][col2];
        else return sum[row2][col2] - sum[row2][col1-1] - sum[row1-1][col2] + sum[row1-1][col1-1];
     
    }
};
