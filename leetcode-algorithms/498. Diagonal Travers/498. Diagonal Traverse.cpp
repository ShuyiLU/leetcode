class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
        int n = matrix.size();
		if(n == 0) return vector<int> {};
		int m = matrix[0].size();
		if(m == 0) return vector<int> {};
		
		vector<vector<int>> dir = {{-1,1},{1,-1}};
		vector<int> res(n*m);
		
		int row=0, col=0, k=0;
		
		for(int i=0; i<n*m; i++){
			res[i] = matrix[row][col];
			
			row += dir[k][0]; //�����ϣ��������£�
			col += dir[k][1]; //�����ң���������
			
			if(col+1 > m){
				col = col-1;
				row +=2;  //֮ǰ��-1�� ���+2
				k = 1-k; //��������
			}
			
			if(row+1 > n){
				row = row-1;
				col += 2;
				k = 1-k; //��������
			}
			
			if(col<0){
				col = col+1;
				k = 1-k;
			}
			
			if(row<0) {
				row = row+1;
				k = 1-k;
			}
			
			
		}
		return res;
    }
};
