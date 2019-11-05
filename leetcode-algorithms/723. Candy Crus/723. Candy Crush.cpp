class Solution {
public:
    vector<vector<int>> candyCrush(vector<vector<int>>& board) {
        int n = board.size();
		int m = board[0].size();
		
		while(true){
			vector<pair<int, int>> del;
			for(int i=0; i<n; i++){
				for(int j=0; j<m; j++){
					if(board[i][j] == 0) continue;
					int x0 = i, x1 = i, y0 = j, y1 = j;
					while(x0 >= 0 && board[x0][j] == board[i][j]) x0--;
					while(x1 < n && board[x1][j] == board[i][j]) x1++;
					while(y0 >= 0 && board[i][y0] == board[i][j]) y0--;
					while(y1 < m && board[i][y1] == board[i][j]) y1++;
					if(x1- x0 > 3  || y1 - y0 > 3) del.push_back(make_pair(i, j));
				}
			}
			
			
			if(del.empty()) break;
			for(auto d:del) board[d.first][d.second] = 0;
			
			for(int j=0; j<m; j++){
				int t = n-1;
				for(int i=n-1; i>=0; i--){
					if(board[i][j] != 0){
						swap(board[i][j], board[t][j]); //0从底部到顶部
						t--;
					}
				}
			}
		}
		return board;
		
    }
};
