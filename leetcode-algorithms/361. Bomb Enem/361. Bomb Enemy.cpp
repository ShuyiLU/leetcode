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
        		if(j == 0 || grid[i][j-1] == 'W'){ //��ǽ���·���ʼ��������ǰ�л��ж���e 
        			rows = 0;
        			for(int k=j; k<m; k++){
        				if(grid[i][k] == 'W') break;
        				if(grid[i][k] == 'E') rows += 1;
					}
				}
				
				if(i == 0 || grid[i-1][j] == 'W'){ //��ǽ���ұ߿�ʼ���� ����ǰ�л��ж���e 
					cols[j] = 0;
					for(int k=i; k<n; k++){
						if(grid[k][j] == 'W') break;
						if(grid[k][j] == 'E') cols[j] += 1;
					}
				} 
				
				if(grid[i][j] == '0') res = max(rows + col[j], res); //�Ѹ��µ����и��Ե�e����ǰ����õ��к��е�e֮�� 
				
			}
			return res;
		}
    }
};
