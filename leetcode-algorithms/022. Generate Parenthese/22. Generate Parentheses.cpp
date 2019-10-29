#include<iostream>
#include<vector>
#include<cstring>

using namespace std; 

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        backtrack("", res, n, n);
        return res;
        
    }
    
    void backtrack(string tmp, vector<string> &res, int l, int r){
    	if(l == 0 && r == 0){
    		res.push_back(tmp);
    		return;
		}
		
		if(l > 0){
			backtrack(tmp+'(', res, l-1, r);
		}
		
		if(l < r){
			backtrack(tmp+')', res, l, r-1);
		}
		
	}
    
};


class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        backtrack(0,0,0,n,res, "");
        return res;
    }
    
     void backtrack(int level, int l, int r, int n, vector<string> & res, string tmp){
     	if(l==r && l==n){
     		res.push_back(tmp);
     		return;
		 }
		 
		 else if(l > n || r>n) return;
		 
		 backtrack(level+1, l+1, r, n, res, tmp+'(');
		 level--;
		 if(r<l) backtrack(level+1, l, r+1, n, res, tmp+')');
		 
		 
	 }
    
};


class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        backtrack(0,0,n,res, "");
        return res;
    }
    
     void backtrack(int l, int r, int n, vector<string> & res, string tmp){
     	if(l==r && l==n){
     		res.push_back(tmp);
     		return;
		 }
		 
		 //else if((l > n || r>n) && (l!=n || r!=n)) return;
		 
		 if(l<n) backtrack(l+1, r, n, res, tmp+'(');
		 if(l>r) backtrack(l, r+1, n, res, tmp+')');
		 
 		 
	 }
    
};


int main(){
	
}
