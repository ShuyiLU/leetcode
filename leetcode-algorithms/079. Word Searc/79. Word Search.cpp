#include<iostream>
#include<vector>
#include<cstring>

using namespace std;

/*
class Solution {
public:
    bool exist(vector<vector<char> >& board, string word) {
         int len = word.size();
         
         int n = board.size();
         if(n == 0 && len == 0) return true;
         if(len == 0) return true;
         if(n == 0) return false;
         int m = board[0].size();
         if(m == 0) return false;
         
         for(int i=0; i<n; i++){
         	for(int j=0; j<m; j++){
         		
         			if(bt(board, word, i, j, 0))
         				return true;
				
			 }
		 }       
         return false;       		     
    }
    
    bool bt(vector<vector<char> >& board, string word, int i, int j, int pos){
    	int n = board.size();
    	int m = board[0].size();
    	
    	if(pos == word.size()) {
    		//cout << s << endl;
    		return true;
		}
    	if(i>=n || j>=m || i<0 || j<0) {
    		//cout << s << endl;
    		return false;
		}   
		
		if(word[pos] != board[i][j]) return false;
		
		char tmp = board[i][j];
		
		board[i][j] = '.';
        bool res = bt(board,word,i+1,j,pos+1) || bt(board,word,i-1,j,pos+1) || bt(board,word,i,j-1,pos+1) || bt(board,word,i,j+1,pos+1);
		
		board[i][j] = tmp;
		return res;
		 
	}
      
};

*/

class Solution {
public:
    bool exist(vector<vector<char> >& board, string word) {
        int len = word.size();
         
        int n = board.size();
        if(n == 0 && len == 0) return true;
        if(len == 0) return true;
        if(n == 0) return false;
        int m = board[0].size();
        if(m == 0) return false;
        
        vector<vector<vector<int> > > v;
        v.resize(len);
        for(int i=0; i<len; i++) v[i].resize(n);
        for(int i=0; i<len; i++){
        	for(int j=0; j<n; j++) v[i][j].resize(m);
		}
        //v[k][i][j]: from(i,j) if can reach word[k], =1, else =0;
        
        for(int k=0; k<len; k++){
        	for(int i=0; i<n; i++){
        		for(int j=0; j<m; j++){
        			if(k==0){
        				if(board[i][j] == word[k]) v[k][i][j] = 1;
						else v[k][i][j] = 0; 
					}
					else{
						if(j-1>=0 && v[k-1][i][j-1] == 1 && board[i][j] == word[k]) {
							v[k][i][j] = 1;
							continue;
						}
						if(i-1>=0 && v[k-1][i-1][j] == 1 && board[i][j] == word[k]){
							v[k][i][j] = 1;
							continue;
						} 
						if(j+1<m && v[k-1][i][j+1] == 1 && board[i][j] == word[k]){
							v[k][i][j] = 1;
							continue;
						} 
						if(i+1<n && v[k-1][i+1][j] == 1 && board[i][j] == word[k]) {
							v[k][i][j] = 1;	
							continue;
						}
					}
				}
			}
		}
        
        for(int i=0; i<n; i++){
        	for(int j=0; j<m; j++){
        		if(v[len-1][i][j] == 1) return true;
			}
		}
		
		return false;
        
    } 
};


int main(){
	int n, m;
	string s;
	cin >> n >> m;
	cin >> s;
	char a;
	vector<char> row;
	vector<vector<char> > col;
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			cin >> a;
			row.push_back(a);
		}
		col.push_back(row);
		row.clear();
	}
	
	Solution sol;
	if(sol.exist(col, s)) cout << "t" << endl;
	else cout << "f" << endl;
}
