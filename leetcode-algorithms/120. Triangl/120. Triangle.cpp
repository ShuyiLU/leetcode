#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    int minimumTotal(vector<vector<int> >& t) {
        int n = t.size();
        if(n == 0) return 0;
        if(t[0].size() == 0) return 0;
        
        vector<vector<int> > f;
        f.resize(n);
        for(int i=0; i<n; i++){
        	f[i].resize(t[i].size());
		}
        
        for(int i=0; i<n; i++){
        	for(int j=0; j<t[i].size(); j++){
        		if(i == 0) f[i][j] = t[i][j];
        		else{
        			if(j-1>=0 && j<t[i-1].size()){
        				f[i][j] = t[i][j] + min(f[i-1][j-1], f[i-1][j]);
					}
					
					else if(j == 0) f[i][j] = t[i][j] + f[i-1][j];
					else if(j >= t[i-1].size()) f[i][j] = t[i][j] + f[i-1][j-1];
				}
			}
		}
		
		sort(f[n-1].begin(), f[n-1].end());
		return f[n-1][0];
        
        
    }
};


int main(){
	
}
