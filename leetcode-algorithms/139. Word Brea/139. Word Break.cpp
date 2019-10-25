#include<iostream>
#include<vector>
#include<cstring>
#include<set>

using namespace std;

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        if(wordDict.size() == 0) return false;
        if(s.length() == 0) return false;
        int n = s.length();
        vector<bool> f(n+1, false);
        
        set<string> st;
        for(int i=0; i<wordDict.size(); i++) st.insert(wordDict[i]);
        f[0] = true;  //f[j]: 0~j-1 
        
        for(int i=0; i<n; i++){
        	
        	for(int j=0; j<=i; j++){  //f[i] = f[j] && f[substr(j, i)]
        		if(f[j]){
        			string tmp = s.substr(j, i-j+1);
        			if(st.count(tmp) > 0) {
        				if(i+1 <= n){
        					f[i+1] = true;
        					break;
						}                  
        				
					}
        			
				}
        		
			}
		}
		/*
		for(int i=0; i<=n; i++) {
			cout << "i: ";
			if(f[i]) cout << "t" << endl;
			else cout << "f" << endl;
		}
		*/
        
        return f[n];
        
    }
};

int main(){
	int n;
	string s;
	cin >> s;
	cin >> n;
	string tmp;
	vector<string> v;
	for(int i=0; i<n; i++){
		cin >> tmp;
		v.push_back(tmp);
	}
	
	Solution sol;
	if(sol.wordBreak(s,v)) cout << "t" << endl;
	else cout << "f" << endl;
}
