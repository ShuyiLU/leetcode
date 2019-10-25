#include<iostream>
#include<vector>
#include<cstring>

using namespace std;

class Solution {
public:
    string findContestMatch(int n) {
        vector<string> s;
        for(int i=0; i<n; i++) {
        	s.push_back(to_string(i+1));
		}
		
		while(s.size()>1) s = merge (s);
     	return s[0];   
    }
    
    vector<string> merge(vector<string> s){
    	vector<string> res;
    	for(int i=0; i<s.size()/2; i++){
    		res.push_back("(" + s[i] + "," + s[s.size()-i-1] + ")") ;
		}
		return res;
	}
};
