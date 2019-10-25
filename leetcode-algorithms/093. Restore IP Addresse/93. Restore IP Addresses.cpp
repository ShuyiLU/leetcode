#include<iostream>
#include<cstring>
#include<vector>

using namespace std; 

class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
    	int n = s.length();
		if(n<4 || n>12) return vector<string>{};
		vector<string> res;
		//string tmp('a', n+3);
		
		backtrack(s, res, 4, "");
		return res;
		    
    }
    
    void backtrack(string s, vector<string>& res, int k, string tmp){ //k是第几段还没分 
    	if(k == 0 && s.empty()){
    		res.push_back(tmp);
    		return;
		}
		
		for(int i=1; i<=3; i++){
			if(s.size() >= i && isValid(s.substr(0,i)) ){
				if(k == 1) backtrack(s.substr(i),res, k-1, tmp+s.substr(0,i));
				else backtrack(s.substr(i), res, k-1, tmp+s.substr(0,i)+"." ); //i代表k段取多少位 
			}
		}
		
		
		
		
	}
	
	bool isValid(string s){
		if((s.length() > 1 && s[0] == '0') || stoi(s) > 255 || stoi(s) < 0) return false;
		return true;
	}
    
    
};
