#include<iostream>
#include<vector>

using namespace std; 

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int> >& matrix) {
        int n = matrix.size();
        if(n == 0) return vector<int>{};
        int m = matrix[0].size();
        if(m == 0) return vector<int>{};
        vector<vector<int> > judge;
        
        vector<int> v;
        if(n==1 && m==1) return vector<int>{matrix[0][0]};
        if(n == 1){
        	for(int j=0; j<m; j++){
        		v.push_back(matrix[0][j]);
			}
			return v;
		}
		
		if(m == 1){
        	for(int i=0; i<n; i++){
        		v.push_back(matrix[i][0]);
			}
			return v;
		}
        
        judge.resize(n);
        for(int i=0; i<n; i++) judge[i].resize(m);
        
        for(int i=0; i<n; i++){
        	for(int j=0; j<m; j++){
        		judge[i][j] = 0;
			}
		}
        
        
        
        int k = 0;
        int a=0, b=0;
        //v.push_back(matrix[a][b]);
        
        while(judge[a][b] != 1 && a<n && b<m){
        	while(b<m && judge[a][b] == 0){
        		judge[a][b] = 1;
        		v.push_back(matrix[a][b]);
        		b++;
			}
			b--;
			a++;
			while(a<n && judge[a][b] == 0){
				judge[a][b] = 1;
				v.push_back(matrix[a][b]);
				a++;
			}
			a--;
			b--;
			
			while(b>=0 && judge[a][b] == 0){
				judge[a][b] = 1;
				v.push_back(matrix[a][b]);
				b--;
			}
			b++;
			a--;
			while(a>=0 && judge[a][b] == 0){
				judge[a][b] = 1;
				v.push_back(matrix[a][b]);
				a--;
			}
			a++;
			
		//	a++;
			b++;
			
		}
        return v;
        
    }
};

int main(){
	int n,m;
	cin >> n >> m;
	vector<int> re;
	int a;
	vector<int> col;
	vector<vector<int> > row;
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			cin >> a;
			col.push_back(a);
		}
		row.push_back(col);
		col.clear();
	}
	Solution sol;
	re = sol.spiralOrder(row);
	for(int i=0; i<n*m; i++) cout << re[i] << " ";
	cout << endl;
}
