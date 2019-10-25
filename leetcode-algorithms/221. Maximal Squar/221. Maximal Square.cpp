#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

/*
class Solution {
public:
    int maximalSquare(vector<vector<char> >& matrix) {
        int n = matrix.size();
        if(n == 0) return 0;
        int m = matrix[0].size();
        vector<vector<vector<int> > > f;
		f.resize(n);
		for(int i=0; i<n; i++) f[i].resize(m);
		int k = min(n, m);    
		for(int i=0; i<n; i++){
			for(int j=0; j<m; j++){
				f[i][j].resize(k+1);
			}
		}
		int flag = 0;
		for(int i = 0; i<n; i++){
			for(int j=0; j<m; j++){
				for(int z=1; z<=k; z++){
					if(z == 1){
						if(matrix[i][j] == '1') f[i][j][z] = 1;
						else f[i][j][z] = 0;
					}
					else{
						//flag = 0;
						if(f[i][j][z-1] == 0){
							f[i][j][z] = 0;
						}
						else{
							if(i+z-1 >= n || j+z-1 >=m) {
								f[i][j][z] = 0;
								break;
							}
							for(int a=i; a<i+z&&a<n; a++){
								if(matrix[a][j+z-1] == '0'){
									f[a][j][z] = 0;
									flag = 1;
								} 
							}
							if(flag == 0){
								for(int b=j; b<j+z&&b<m; b++){
									if(matrix[i+z-1][b] == '0'){
										f[i][b][z] = 0;
										flag = 1;
									}
								}
							}
							if(flag == 0) f[i][j][z] = 1;
							flag = 0;
						}
					}
					
				}
			}
		}
		int res = 0;
		
		for(int z=k; z>=1; z--){
			for(int i=0; i<n; i++){
				for(int j=0; j<m; j++){
					if(f[i][j][z] == 1){
						res = z*z;
						return res;
					}
				}
			}
		}
		
		 return res;   
    }
};
*/

class Solution {
public:
    int maximalSquare(vector<vector<char> >& matrix) {
        int n = matrix.size();
        if(n == 0) return 0;
        int m = matrix[0].size();
        vector<vector<int> > f;
		f.resize(n);
		for(int i=0; i<n; i++) f[i].resize(m);
		
		//f[i][j] : the max area to (i,j)
		for(int i=0; i<n; i++){
			for(int j=0; j<m; j++){
				f[i][j] = 0;
			}
		}
		
		int max_s = 0;
		
		for(int i=0; i<n; i++){
			for(int j=0; j<m; j++){
				if(i==0 || j==0){
					if(matrix[i][j] == '1') f[i][j] = 1;
					else f[i][j] = 0;
					max_s = max(f[i][j], max_s);
				}
				else{
					if(matrix[i][j] == '1' ){
						f[i][j] = min(min(f[i-1][j], f[i][j-1]), f[i-1][j-1]) + 1;
						max_s = max(f[i][j], max_s);
					}
				}
			}
		}
		    
		return max_s * max_s;
		
    }
};

int main(){
	int n, m;
	cin >> n >> m;
	vector<char> v1;
	vector<vector<char> > v2;
	char c;
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			cin >> c;
			v1.push_back(c);
		}
		v2.push_back(v1);
		v1.clear();
		
	}
	
	int res;
	Solution sol;
	res = sol.maximalSquare(v2);
	cout << res << endl;
	
	
}
