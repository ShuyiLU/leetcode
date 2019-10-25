#include<iostream>
#include<vector>
#include<cstring>

using namespace std;
/*
class Solution {
private:
	vector<int> rank;
	vector<int> father;
	
public:
	
	int findFa(int a){
		if(father[a] == a) return a;
		else return father[a] = findFa(father[a]);
		//while(a!=father[a]) a = father[a];
		//return a;
	}
	
	void unionFa(int a, int b){
		int fa = findFa(a);
		int fb = findFa(b);
		if(fa == fb) return;
		
		if(rank[fa] < rank[fb]) {
			father[fa] = fb;
		}
		
		else{
			if(rank[fa] == rank[fb]) rank[fa]++;
			father[fb] = fa;
		}
	}
	
	
    void solve(vector<vector<char> >& board) {
        int n = board.size();
        if(n == 0) return;
        int m = board[0].size();
        if(m == 0) return;
        
        rank.resize(n*m);
        father.resize(n*m);
        
        for(int i=0; i<n*m; i++) father[i] = i;
        for(int i=0; i<n*m; i++) rank[i] = 1;
        
        for(int i=0; i<n; i++){
        	for(int j=0; j<m; j++){
        		int k = i*m+j;
        		int r = k+1;
        		int b = k+m;
        		if(j+1<m && board[i][j] == board[i][j+1]) unionFa(k,r);
        		if(i+1<n && board[i][j] == board[i+1][j]) unionFa(k,b);
			}
		}
		
		/*
		for(int i=0; i<n; i++){
			for(int j=0; j<m; j++){
				cout << father[i*m+j] << " ";
			}
			cout << endl;
		}
		*/
		/*
		for(int i=0; i<n; i++){
			for(int j=0; j<m; j++){
				if((i==0 || j==0 || i == n-1 || j == m-1) && board[i][j] == 'O'){
					int tmp = father[i*m+j];
					for(int k=0; k<n*m; k++){
						if(father[k] == tmp) father[k] = -1;
					}
				}
				else continue;
			}
		}*/
		/*
		for(int i=0; i<n; i++){
			for(int j=0; j<m; j++){
				cout << father[i*m+j] << " ";
			}
			cout << endl;
		}
		*/
		/*
		for(int i=0; i<n*m; i++){
			if(father[i] == i && board[i/m][i%m] == 'O'){
				int tmp = i;
				for(int k=0; k<n*m; k++) {
					if(father[k] == tmp) board[k/m][k%m] = 'X';
				}
					
			}
		}*/
        /*
        for(int i=0; i<n; i++){
			for(int j=0; j<m; j++){
				cout << board[i][j] << " ";
			}
			cout << endl;
		}
		*//*
    }
};
*/


class Solution {
	
public:
	
	void edge(vector<vector<char> >& board, int i, int j){
		int n=board.size();
		int m=board[0].size();
		if(i<0 || j<0 || i>=n || j>=m) return;
		board[i][j] = 'V';
		if(i-1>=0 && board[i-1][j] == 'O') edge(board, i-1, j);
		if(j-1>=0 && board[i][j-1] == 'O') edge(board, i, j-1);
		if(i+1<n && board[i+1][j] == 'O') edge(board, i+1, j);
		if(j+1<m && board[i][j+1] == 'O') edge(board, i, j+1);
	}
	
	
    void solve(vector<vector<char> >& board) {
        int n = board.size();
        if(n == 0) return;
        int m = board[0].size();
        if(m == 0) return;
        
        for(int i=0; i<n; i++){
			for(int j=0; j<m; j++){
				if((i==0 || j==0 || i == n-1 || j == m-1) && board[i][j] == 'O'){
					edge(board, i, j);
				}
				else continue;
			}
		}
	
		
        
        for(int i=0; i<n; i++){
			for(int j=0; j<m; j++){
				if(board[i][j] == 'O') board[i][j] = 'X';
			}
		}
		
		for(int i=0; i<n; i++){
			for(int j=0; j<m; j++){
				if(board[i][j] == 'V') board[i][j] = 'O';
			}
		}
		
		
		
    }
};


int main(){
	int n, m;
	cin >> n >> m;
	vector<char> col;
	vector<vector<char> > row;
	char a;
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			cin >> a;
			col.push_back(a);
		}
		row.push_back(col);
		col.clear();
		
	}
	
	Solution sol;
		sol.solve(row);
}
