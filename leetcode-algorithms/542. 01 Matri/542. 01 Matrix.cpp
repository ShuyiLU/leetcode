#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;
/* can not do in dfs
class Solution {
private:
//	int count = 0;
	int k = 0;
public:
    vector<vector<int> > updateMatrix(vector<vector<int> >& matrix) {
        int n = matrix.size();
        if(n==0) return vector<vector<int> > {};
        int m = matrix[0].size();
        if(m==0) return vector<vector<int> > {};
        
        vector<vector<int> > ans;
        ans.resize(n);
        for(int i=0; i<n; i++)ans[i].resize(m);
        for(int i=0; i<n; i++){
        	for(int j=0; j<m; j++)
        		ans[i][j] = -1;
		}
        
        for(int i=0; i<n; i++){
        	for(int j=0; j<m; j++){
        		cout << k++ << endl;
        		if(matrix[i][j] == 0) ans[i][j] = 0;
        		else{
        			ans[i][j] = dfs(matrix, i, j, 0);
				}
        		
			}
		}
        
        return ans;
    }
    
    
    int dfs(vector<vector<int> > matrix, int i, int j, int count){
    	int n = matrix.size();
    	int m = matrix[0].size();
    	if(i<0 || j<0 || i>=n || j>=m) return -1;
    	if(matrix[i][j] == 0) return count;  	
    	int ans[4];
    	for(int i=0; i<4; i++) ans[i] = -1;
    	count++;
    	if(i-1>=0) ans[0] = dfs(matrix, i-1, j, count);
    	if(i+1<n) ans[1] = dfs(matrix, i+1, j, count);
    	if(j-1>=0) ans[2] = dfs(matrix, i, j-1, count);
    	if(j+1<m) ans[3] = dfs(matrix, i, j+1, count);
    	sort(ans, ans+4);
    	int a;
    	for(int i=0; i<4; i++){
    		if(ans[i] >= 0) {
    			a = ans[i];
    			break;
			}
		}
		return a;    	
	}	
};
*/
/*
class Solution {
public:
    vector<vector<int> > updateMatrix(vector<vector<int> >& matrix) {
        int n = matrix.size();
        if(n==0) return vector<vector<int> > {};
        int m = matrix[0].size();
        if(m==0) return vector<vector<int> > {};
        
	//	queue<int> q;
        
        vector<vector<int> > ans;
        ans.resize(n);
        for(int i=0; i<n; i++)ans[i].resize(m);
        
        
        for(int i=0; i<n; i++){
        	for(int j=0; j<m; j++){
        		if(matrix[i][j] == 0) ans[i][j] = 0;
        		else{
        			ans[i][j] = bfs(matrix, i, j);
				}
			}
		}
		
		return ans;    
    }
    
    int bfs(vector<vector<int> >& matrix, int i, int j){
    	int n = matrix.size();
    	int m = matrix[0].size();
    	queue <pair<pair<int, int>, int> > q;
    	while(!q.empty()) {
    		q.pop();
		}
    	q.push(make_pair(make_pair(i, j), 0));
    	
    	while(!q.empty()){
    		
    		pair<pair<int, int>, int> p = q.front();
    		q.pop();
    		
    		int d = p.second;
    		
    		if(matrix[p.first.first][p.first.second] == 0) return d;
    		
    		if(p.first.first-1>=0) q.push(make_pair(make_pair(p.first.first-1, p.first.second), d+1));
    		if(p.first.second-1>=0) q.push(make_pair(make_pair(p.first.first, p.first.second-1), d+1));
    		if(p.first.first+1<n) q.push(make_pair(make_pair(p.first.first+1, p.first.second), d+1));
    		if(p.first.second+1<m) q.push(make_pair(make_pair(p.first.first, p.first.second+1), d+1)); 		
  		
		}
      	return 0;
	}
      
};
*/ 

class Solution {
public:
    vector<vector<int> > updateMatrix(vector<vector<int> >& matrix) {
        int n = matrix.size();
        if(n==0) return vector<vector<int> > {};
        int m = matrix[0].size();
        if(m==0) return vector<vector<int> > {};
        
	//	queue< pair< pair <int, int> , int> > q;
      	queue<pair<int, int> > q;
		    
        vector<vector<int> > ans;
        ans.resize(n);
        for(int i=0; i<n; i++)ans[i].resize(m);
        
        for(int i=0; i<n; i++){
        	for(int j=0; j<m; j++){
        		if(matrix[i][j] == 0) {
        			ans[i][j] = 0;
        			q.push(make_pair(i, j));
				}
				else{
					ans[i][j] = -1;
				}
			}
		}
		
		while(!q.empty()){
			//pair< pair<int, int>, int> p = q.front();
			pair<int, int> p = q.front();
			q.pop();
			int p1 = p.first;
			int p2 = p.second;
			int d = ans[p.first][p.second];
			
			if(p1-1>=0){
				if(ans[p1-1][p2] == -1){
					ans[p1-1][p2] = d+1;
					q.push(make_pair(p1-1, p2) );
				}
			}
			
			if(p1+1<n){
				if(ans[p1+1][p2] == -1){
					ans[p1+1][p2] = d+1;
					q.push(make_pair(p1+1, p2) );
				}
			}
			
			if(p2-1>=0){
				if(ans[p1][p2-1] == -1){
					ans[p1][p2-1] = d+1;
					q.push(make_pair(p1, p2-1) );
				}
			}
			
			if(p2+1<m){
				if(ans[p1][p2+1] == -1){
					ans[p1][p2+1] = d+1;
					q.push(make_pair(p1, p2+1) );
				}
			}
				
			
		}
		
        return ans;
        
    }
};


int main(){
	int n, m;
	cin >> n >> m;
	int a;
	vector<int> row;
	vector< vector <int> > col;
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			cin >> a;
			row.push_back(a);
		}
		col.push_back(row);
		row.clear();
	}
	/*
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			cout << col[i][j] <<" ";
		}
		cout << endl;
	}
	*/
	
	vector< vector <int> > as;
	Solution sol;
	as = sol.updateMatrix(col);
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			cout << as[i][j] <<" ";
		}
		cout << endl;
	}
	
}
