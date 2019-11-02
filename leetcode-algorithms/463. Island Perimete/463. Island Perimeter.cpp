class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        const int mv[4]={1,-1,0,0};
        int n=grid.size(); if (!n) return 0;
        int m=grid[0].size(); if (!m) return 0;
        int ans=0;
        for (int i=0; i<n; i++) for (int j=0; j<m; j++) if (grid[i][j]) {
            for (int k=0; k<4; k++) {
                int x=i+mv[k], y=j+mv[3-k];
                if (!(0<=x&&x<n&&0<=y&&y<m)||grid[x][y]==0) ans++;
            }
        }
        return ans;
    }
};
