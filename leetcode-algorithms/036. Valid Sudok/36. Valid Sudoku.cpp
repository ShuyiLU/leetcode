#include<iostream>
#include<vector>
#include<map>

using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char> >& board) {
        if(board.size() == 0) return false;
        if(board[0].size() == 0) return false;
        int n = board.size();
        int m = board[0].size();
        map<int, int> mp; //(key, count)
        //int flag = 0;
        for(int i=0; i<n; i++){
        	if(!mp.empty())mp.clear();
        	for(int j=0; j<m; j++){
        		if(board[i][j] >= '0' && board[i][j] <= '9'){
        			if(mp.count(board[i][j]) > 0) return false;
        			else mp[board[i][j]] = 1;
				}
			}
		}
		
        for(int j=0; j<m; j++){
        	if(!mp.empty())mp.clear();
        	for(int i=0; i<n; i++){
        		if(board[i][j] >= '0' && board[i][j] <= '9'){
        			if(mp.count(board[i][j]) > 0) return false;
        			else mp[board[i][j]] = 1;
				}
			}
		}
		
		for(int k=0; k<=8; k++){
			if(!mp.empty()) mp.clear();
			for(int i=0; i<3; i++){
				for(int j=0; j<3; j++){
					if(board[i+k/3*3][j+k%3*3] >= '0' && board[i+k/3*3][j+k%3*3] <= '9'){
						if(mp.count(board[i+k/3*3][j+k%3*3]) > 0) return false;
        				else mp[board[i+k/3*3][j+k%3*3]] = 1;
					}
				}
			}
		}
		return true;
    }
}; 

int main(){
	int n, m;
	char a;
	vector<char> col;
	vector< vector<char> > row;
	cin >> n >> m;
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			cin >> a;
			col.push_back(a);
		}
		row.push_back(col);
		col.clear();
	}
	Solution sol;
	if(sol.isValidSudoku(row)) cout<< "true" << endl;
	else cout << "false" << endl;;
	return 0;
}
