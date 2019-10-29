#include<iostream>
#include<cstring>

using namespace std; 

class Solution {
public:
    vector<vector<string> > partition(string s) {
        vector<vector<string> > res;
        vector<string> tmp;
        backtrack(res, s, 0, tmp, "");
        return res;
    }
    
    void backtrack(vector<vcetor<string> > &res, string s, string index, vector<string> tmp, string str){
    	if(index == s.length()){
    		res.push_back(tmp);
    		return res;
		}
		
		if(isPal(str))
		
	}
	
	bool isPal(string s){
		for(int i=0; i<s.length()/2; i++){
			if(s[i] != s[s.length()-1-i]) return false;
			return true;
		}
	}
    
};
