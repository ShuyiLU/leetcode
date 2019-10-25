#include<iostream>
#include<vector>
#include<cstring>
#include<stack>
#include<algorithm>

using namespace std; 

class Solution {
public:
    vector<string> expand(string S) {
        int n=0;
        vector<string> group;
        int flag = 0;
        for(int i=0; i<S.length(); i++){
        	if(S[i] <= 'z' && S[i] >= 'a'){
        		if(flag == 0){
        			n++;
        			if(group.size() < n) group.push_back({});
					group[n-1].push_back(S[i]);
				}
				else{
					if(group.size() < n) group.push_back({});
					group[n-1].push_back(S[i]);
				}
        		
			}
			else if(S[i] == '{') {
				flag = 1;
				n++;
			}
			else if(S[i] == '}'){
				flag = 0;
			}
		}
		for(int i=0; i<group.size(); i++){
			sort(group[i].begin(), group[i].end());
		}
		vector<string> res;
		backtrack(res, 0, n, "", group);
		return res;
		
    }
    void backtrack(vector<string> &res, int i, int n, string tmp, vector<string> &group){
    	if(i == n){
    		res.push_back(tmp);
    		return;
		}
		for(int j=0; j<group[i].length(); j++){
			backtrack(res, i+1, n, tmp+group[i][j], group);
		}
	}
    
};


int main(){
	string s;
	cin >> s;
	vector<string> v;
	Solution sol;
	v = sol.expand(s);
	for(int i=0; i<v.size(); i++){
		cout << v[i] << endl;
	}
}
