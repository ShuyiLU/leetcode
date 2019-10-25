#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int> >& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        /*
		int a[n][m];
        for(int i=0; i<n; i++){
        	for(int j=0; i<m; j++){
        		a[i][j] = matrix[i][j];
			}
		}
		*/
		int flag = 0;
		int i, j;
		for(i=n-2; i>=0; i--){
			j = 0;
			int p = i; 
			int q = j;
			while(p+1<=n-1 && q+1<=m-1){
				//cout << i << " " << j << " " << matrix[i][j] << endl;
				if(matrix[p][q] != matrix[p+1][q+1]) return false;
				else{
					p++;
					q++;
				}
			}
		}
		for(j=0; j<=m-2; j++){
			i = 0;
			int p = i; 
			int q = j;
			while(p+1<=n-1 && q+1<=m-1){
				//cout << i << " " << j << " " << matrix[i][j] << endl;
				if(matrix[p][q] != matrix[p+1][q+1]) return false;
				else{
					p++;
					q++;
				}
			}
		}
		return true;
    }
};

int main(){
	int n, m;
	int a;
	vector<int> v2;
	vector < vector<int> > v1;
	cin >> n >> m;
	for(int i=0; i<n; i++){
		while(!v2.empty()){
			v2.pop_back();
		}
		for(int j=0; j<m; j++){
			cin >> a;
			v2.push_back(a);
		}	
		v1.push_back(v2);
	} 
	Solution sol;
	if(sol.isToeplitzMatrix(v1)) cout << "true" << endl;
	else cout << "false" << endl;
	return 0;
} 
