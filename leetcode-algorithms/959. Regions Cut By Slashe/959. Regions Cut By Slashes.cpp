#include<iostream>
#include<vector>
#include<cstring>

using namespace std;


class Solution {
public:
	vector<int> fa;
	
	int findFa(int x){
		if(x != fa[x]) fa[x] = findFa(fa[x]);
		else return fa[x];
	}
	
	void unionFa(int x, int y){
		int fa_x = findFa(x);
		int fa_y = findFa(y);
		if(fa_x != fa_y) fa[fa_x] = fa_y; 	
	}
	//up 0, right 1, down 2, left 3
	
    int regionsBySlashes(vector<string>& grid) {
        int n = grid.size();
        fa.resize(4*n*n);
        for(int i=0; i<4*n*n; i++) fa[i] = i;
        for(int i=0; i<n; i++){
        	for(int j=0; j<n-1; j++){
        		int x = 4 * (i*n+j)+1;
        		int y = 4 * (i*n+j+1)+3;
        		unionFa(x,y);
			}
		}
		
		for(int j=0; j<n; j++){
        	for(int i=0; i<n-1; i++){
        		int x = 4 * (i*n+j)+2;
        		int y = 4 * ((i+1)*n+j);
        		unionFa(x,y);
			}
		}
		
        for(int i=0; i<n; i++){
       		for(int j=0; j<n; j++){
       				int x = 4 * (i*n + j);
       				if(grid[i][j] == ' '){
       						unionFa(x, x+1);
       						unionFa(x+1, x+2);
       						unionFa(x+2, x+3);
					}
					else if(grid[i][j] == '/'){
						unionFa(x, x+3);
						unionFa(x+1, x+2);
					}
					else{
						unionFa(x, x+1);
						unionFa(x+2, x+3);
					}
			}
	   	}
	   	
	   	int ans = 0;
	   	for(int i=0; i<4*n*n; i++){
	   		if( i == findFa(i)) ans++;
		   }
       return ans;
    }
};
