#include<iostream>
#include<vector>
#include<queue>

using namespace std;



class Solution {
private:
	int k1, k2;
public:
    vector<pair<int, int> > pacificAtlantic(vector<vector<int> >& matrix) {
    	int n = matrix.size();
    	if(n == 0) return vector<pair<int, int> > {};
    	int m = matrix[0].size();
    	if(m == 0) return vector<pair<int, int> > {};
    	
    	vector<pair<int, int> > v;
    	
    	for(int i=0; i<n; i++){
    		for(int j=0; j<m; j++){
    			int f1 = 0;
    			int f2 = 0;
    			k1=0;
				k2=0;
    			if(i==0 || j==0) {
    				k1 = 1;
    				f1 = 1;
				}
    			if(i==n-1 || j==m-1) {
    				f2 = 1;
    				k2 = 1;
				}
    			if(f1 == 1 && f2 == 1) {
    				v.push_back(make_pair(i,j));
    				break;
				}
				cout << i << " " << j << " " << k1 << " " << k2 << endl;
    			dfs(matrix, i, j, f1, f2);
    			if(f1 == 1 && f2 == 1) v.push_back(make_pair(i,j));
			}
		}	
    	return v;
    }
    
    void dfs(vector<vector<int> >& matrix, int i, int j, int& f1, int& f2){
    	int n = matrix.size();
    	int m = matrix[0].size();
    	
    	if(i == 0 || j == 0){
    		if(k1 == 1) k1 = 0;
    		else{
    			f1 = 1;
    			return;
			}
    			
		}
		
		if(i == n-1 || j == m-1){
			if(k2 == 1) k2 = 0;
			else{
				f2 = 1;
				return;	
			}
						
		}
		
		if(i-1>=0 && matrix[i-1][j] <= matrix[i][j]) dfs(matrix, i-1, j, f1, f2);
		if(i+1<n && matrix[i+1][j] <= matrix[i][j]) dfs(matrix, i+1, j, f1, f2);
		if(j-1>=0 && matrix[i][j-1] <= matrix[i][j]) dfs(matrix, i, j-1, f1, f2);
		if(j+1<m && matrix[i][j+1] <= matrix[i][j]) dfs(matrix, i, j+1, f1, f2);
    	  	   	
	}

    
};


class Solution {

public:
    vector<pair<int, int> > pacificAtlantic(vector<vector<int> >& matrix) {
    	int n = matrix.size();
    	if(n == 0) return vector<pair<int, int> > {};
    	int m = matrix[0].size();
    	if(m == 0) return vector<pair<int, int> > {};
    	
    	vector<vector<int> > visit1(matrix.size(), vector<int>(matrix[0].size(), -1)); // left, up
    	vector<vector<int> > visit2(matrix.size(), vector<int>(matrix[0].size(), -1)); // right, dow
    	
    	vector<pair<int, int> > v;
    	
    	queue<pair<int, int> > q1, q2;
    	for(int i=0; i<n; i++){
    		for(int j=0; j<m; j++){
    			if(i==0 || j==0) {
    				q1.push(make_pair(i,j));
    				visit1[i][j] = 0;
				}
				if(i==n-1 || j==m-1){
					q2.push(make_pair(i, j));
					visit2[i][j] = 0;
				}
			}
		}
		
		pair<int, int> p;
    	
    	while(!q1.empty()){
    		p = q1.front();
    		q1.pop();
    		if(p.first-1 >= 0 && visit1[p.first-1][p.second] == -1 && matrix[p.first-1][p.second] >= matrix[p.first][p.second]){
    			q1.push(make_pair(p.first-1, p.second));
    			visit1[p.first-1][p.second] = 0;
			}
			if(p.first+1 <n && visit1[p.first+1][p.second] == -1 && matrix[p.first+1][p.second] >= matrix[p.first][p.second]){
    			q1.push(make_pair(p.first+1, p.second));
    			visit1[p.first+1][p.second] = 0;
			}
			if(p.second-1 >= 0 && visit1[p.first][p.second-1] == -1 && matrix[p.first][p.second-1] >= matrix[p.first][p.second]){
    			q1.push(make_pair(p.first, p.second-1));
    			visit1[p.first][p.second-1] = 0;
			}
			if(p.second+1 < m && visit1[p.first][p.second+1] == -1 && matrix[p.first][p.second+1] >= matrix[p.first][p.second]){
    			q1.push(make_pair(p.first, p.second+1));
    			visit1[p.first][p.second+1] = 0;
			}
		}
		
		while(!q2.empty()){
    		p = q2.front();
    		q2.pop();
    		if(p.first-1 >= 0 && visit2[p.first-1][p.second] == -1 && matrix[p.first-1][p.second] >= matrix[p.first][p.second]){
    			q2.push(make_pair(p.first-1, p.second));
    			visit2[p.first-1][p.second] = 0;
			}
			if(p.first+1 <n && visit2[p.first+1][p.second] == -1 && matrix[p.first+1][p.second] >= matrix[p.first][p.second]){
    			q2.push(make_pair(p.first+1, p.second));
    			visit2[p.first+1][p.second] = 0;
			}
			if(p.second-1 >= 0 && visit2[p.first][p.second-1] == -1 && matrix[p.first][p.second-1] >= matrix[p.first][p.second]){
    			q2.push(make_pair(p.first, p.second-1));
    			visit2[p.first][p.second-1] = 0;
			}
			if(p.second+1 < m && visit2[p.first][p.second+1] == -1 && matrix[p.first][p.second+1] >= matrix[p.first][p.second]){
    			q2.push(make_pair(p.first, p.second+1));
    			visit2[p.first][p.second+1] = 0;
			}
		}
		
		for(int i=0; i<n; i++){
			for(int j=0; j<m; j++){
				if(visit1[i][j] == 0 && visit2[i][j] == 0 ) v.push_back(make_pair(i, j));
			}
		}
		/*
    	cout <<"visiti1" << endl;
    	for(int i=0; i<n; i++){
    		for(int j=0; j<m; j++){
    			cout << visit1[i][j] << " ";
			}
			cout << endl;
		}
		
		cout <<"visiti2" << endl;
    	for(int i=0; i<n; i++){
    		for(int j=0; j<m; j++){
    			cout << visit2[i][j] << " ";
			}
			cout << endl;
		}
    	   */	
    	return v;
    }
     
};


int main(){
	int n, m;
	cin >> n >> m;
	int a;
	vector<int> row;
	vector< vector<int> > col;
	for(int i=0; i<n; i++){
		for(int j =0; j<m; j++){
			cin >> a;
			row.push_back(a);
		}
		col.push_back(row);
		row.clear();
	}
	Solution sol;
	vector<pair<int, int> > v;
	v = sol.pacificAtlantic(col);
	for(int i=0; i<v.size(); i++){
		cout << v[i].first << " " << v[i].second << endl;
	}
	return 0;
}
