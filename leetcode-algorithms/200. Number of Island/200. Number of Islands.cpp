#include<iostream>
#include<vector>
#include<cstring>

using namespace std;


/*
class Solution {
public:
    int numIslands(vector<vector<char> >& grid) {
    	int n = grid.size();
    	if(n==0) return 0;
    	int m = grid[0].size();
    	if(m==0) return 0;
    	int count = 0;
    	for(int i=0; i<n; i++){
    		for(int j=0; j<m; j++){
    			if(grid[i][j] == '1') {
    				DFS(grid, i, j);
    				count++;
				}
			}
		}
        return count;
    }
    
    void DFS(vector<vector<char> >& grid, int a, int b){
    	int m = grid[0].size();
    	int n = grid.size();
    	if(a<0 || a>=n || b<0 || b>=m || grid[a][b] != '1') return;
    	grid[a][b] = '2';
    	DFS(grid, a+1, b);
    	DFS(grid, a, b+1);
    	DFS(grid, a-1, b);
    	DFS(grid, a, b-1);
		
	}  
};
*/

class Solution {
private:
	vector<int> father;
	vector<int> rank;
	
public:
	int findFa(int k){
		if(father[k] == k) return k;
		else return father[k] = findFa(father[k]);
	}
	
	void unionFather(int a, int b){
		int fa_a = findFa(a);
		int fa_b = findFa(b);
		if(fa_a == fa_b) return;
		
		if(rank[fa_a] < rank[fa_b]){
			father[fa_a] = fa_b;
		}
		else{
			if(rank[fa_a] == rank[fa_b]) rank[fa_a]++;
			father[fa_b] = fa_a;
		}
		
		//else father[fa_a] = fa_b;
	
		
	}
	
    int numIslands(vector<vector<char> >& grid) {
        if(grid.size() == 0) return 0;
        if(grid[0].size() == 0) return 0;
        int n = grid.size();
        int m = grid[0].size();
        int k = n*m;
        //vector<int> father;
        //vector<int> rank;
        father.resize(k);
       	rank.resize(k);
        for(int i=0; i<k; i++) father[i] = i;
        for(int i=0; i<k; i++) rank[i] = 1;
        for(int i=0; i<n; i++){
        	for(int j=0; j<m; j++){
        		int cur = i*m + j;
        		int cur_nr = cur+m;
        		int cur_nc = cur+1;
        		if(i+1<n && grid[i][j] == grid[i+1][j]) unionFather(cur, cur_nr);
        		if(j+1<m && grid[i][j] == grid[i][j+1]) unionFather(cur, cur_nc);
			}
		}
		int count = 0;
		for(int i=0; i<k; i++){
			if(father[i] == i && grid[i/m][i%m] == '1') count++;
		}
		return count;
    }
};


int main(){
	int n, m;
	cin >> n >> m;
	vector<vector<char> > col;
	vector<char> row;
	char a;
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			cin >> a;
			row.push_back(a);
		}
		col.push_back(row);
		row.clear();
	}
	Solution sol;
	cout << sol.numIslands(col) << endl;
}
