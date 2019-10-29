#include<iostream>
#include<vector>

using namespace std;

class Solution {
private:
	vector<int> Fa;	
	vector<int> rank;
	
public:
	int findFa(int i){
		if(Fa[i] == i) return i;
		else return Fa[i] = findFa(Fa[i]);
	}
	
	void Union(int i, int j){
		int fi = findFa(i);
		int fj = findFa(j);
		if(fi == fj) return;
		if(rank[fi] < rank[fj]) Fa[fi] = fj;
		
		else{
			if(rank[fi] == rank[fj]) rank[fi]++;
			Fa[fj] = fi;	
		}
		//cout << "in Union: " << Fa[fi] << " " << Fa[fj] << endl;
	}
	
	
    int findCircleNum(vector<vector<int> >& M) {
        if(M.size() == 0) return 0;
        if(M[0].size() == 0) return 0;
        int n = M.size();
        Fa.resize(n);
        rank.resize(n);
    	for(int i=0; i<n; i++) Fa[i] = i;
    	for(int i=0; i<n; i++) rank[i] = 1;
        for(int i=0; i<n; i++){
        	for(int j=0; j<n; j++){
        		if((M[i][j] == 1) && (i!=j )) {
        			Union(i,j);
        			//cout << "in solution: " << Fa[i] << " " << Fa[j] << endl;
				} 
			}
		}
        int count = 0;
		for(int i=0; i<n; i++){
			if(Fa[i] == i) count++;
		}        
        return count;
    }
};

int main(){
	int n;
	vector<int> row;
	vector<vector<int> > col;
	int k;
	cin >> n; 
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			cin >> k;
			row.push_back(k);
		}
		col.push_back(row);
		row.clear();
	}
	Solution sol;
	cout << sol.findCircleNum(col) << endl;
}
