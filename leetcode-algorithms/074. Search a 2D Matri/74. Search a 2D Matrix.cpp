class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        if(n == 0) return false;
        int m = matrix[0].size();
        if(m == 0) return false;
        if(target < matrix[0][0] || target > matrix[n-1][m-1]) return false;
        int x=-1, y=-1;
        for(int i=1; i<n; i++){
            if(matrix[i][0] > target){
                x = i-1;
                break;
            }
        }
        if(x == -1) x = n-1;
        if(matrix[x][m-1] < target) return false;
        for(int j=m-1; j>=0; j--){
            if(matrix[x][j] == target) return true;
        }
        return false;
    }
};
