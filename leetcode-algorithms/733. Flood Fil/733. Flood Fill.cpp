#include<iostream>
#include<vector>

using namespace std;
/*
class Solution {
public:
    vector<vector<int> > floodFill(vector<vector<int> >& image, int sr, int sc, int newColor) {
        int n = image.size();
        if(n==0) return image;
        int m = image[0].size();
        if(m==0) return image;
        int old = image[sr][sc];
        DFS(image, sr, sc, old, newColor);
        return image;
        
    }
    
    void DFS(vector<vector<int> >& image, int sr, int sc, int old, int newColor){
    	int n = image.size();
        int m = image[0].size();
        if(sr>=n || sc>=m || sr<0 || sc<0 || image[sr][sc] != old) return;
    	//int origin = image[sr][sc];
    	image[sr][sc] = newColor;
    	 DFS(image, sr+1, sc, old, newColor);
    	 DFS(image, sr-1, sc, old, newColor);
    	 DFS(image, sr, sc+1, old, newColor);
    	 DFS(image, sr, sc-1, old, newColor); 
    	
    	 /*
    	if(sr+1 < n && image[sr+1][sc] == old) DFS(image, sr+1, sc, old, newColor);
    	if(sr-1 >= 0 && image[sr-1][sc] == old) DFS(image, sr-1, sc, old, newColor);
    	if(sc+1 < m && image[sr][sc+1] == old) DFS(image, sr, sc+1, old, newColor);
    	if(sc-1 >= 0 && image[sr][sc-1] == old) DFS(image, sr, sc-1, old, newColor); 
		*/ 
		  	
//	} 
//};
//*/

class Solution {
public:
    vector<vector<int> > floodFill(vector<vector<int> >& image, int sr, int sc, int newColor) {
        int n = image.size();
        if(n==0) return vector<vector<int> > {};
        int m = image[0].size();
        if(m==0) return vector<vector<int> > {};
        int old = image[sr][sc];
        if(old!=newColor)
        	DFS(image, sr, sc, old, newColor);
        return image;
        
    }
    
    void DFS(vector<vector<int> >& image, int sr, int sc, int old, int newColor){
    	int n = image.size();
        int m = image[0].size();
        if(sr>=n || sc>=m || sr<0 || sc<0 || image[sr][sc] != old) return; 
    	image[sr][sc] = newColor;
    	if(sr+1 < n && image[sr+1][sc] == old) DFS(image, sr+1, sc, old, newColor);
    	if(sr-1 >= 0 && image[sr-1][sc] == old) DFS(image, sr-1, sc, old, newColor);
    	if(sc+1 < m && image[sr][sc+1] == old) DFS(image, sr, sc+1, old, newColor);
    	if(sc-1 >= 0 && image[sr][sc-1] == old) DFS(image, sr, sc-1, old, newColor);    	
	} 
};

int main(){
	vector<int> col;
	vector<vector<int> > row;
	int n,m;
	cin >> n >> m;
	int a;
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			cin >> a;
			col.push_back(a);
		}
		row.push_back(col);
		col.clear();
	}
	Solution sol;
	sol.floodFill(row, 1, 1, 1);
	for(int i=0; i<row.size(); i++){
		for(int j=0; j<row[0].size(); j++){
			cout << row[i][j] << " ";
		}
		cout << endl;
	}
}
