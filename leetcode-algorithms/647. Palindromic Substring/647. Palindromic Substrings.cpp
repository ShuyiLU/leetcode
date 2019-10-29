#include<iostream>
#include<cstring>
#include<vector>

using namespace std;

class Solution {
public:
    int countSubstrings(string s) {
        int n = s.length();
        if(n <= 1) return n;
        vector<vector<int> > v;
        int count = 0;
        v.resize(n); // v[i][j] = 1 : is palidrome substring from i to j;
        for(int i=0; i<n; i++) v[i].resize(n);
        for(int i=n-1; i>=0; i--){
        	for(int j=n-1; j>=0; j--){
        		
        		if(i > j) v[i][j] = 0;
        		
        		else if(i == j) {
        			v[i][j] = 1;
        			count++;
        		//	cout << i << " " << j << endl;
				}
				
        		else{		
        			if(j == i+1) {
        				if(s[i] == s[j]){
        					v[i][j] = 1;
        					count++;
        				//	cout << i << " " << j << endl;	
						}
						else v[i][j] = 0;        				
					}					
					else{
						
						if(v[i+1][j-1] != 1){
        					if(s[i] == s[j]) v[i][j] = 0;
        					else {
        						v[i][j] = 0;
							}
						}
        			
        				else{
        					if(s[i] == s[j]) {
        						v[i][j] = 1;
        						count++;
        						//cout << i << " " << j << endl;
							}
        					else v[i][j] = 0;
						}		
					}     			    			
				}
			}
		}
        return count;
    }
    
    /*
    bool isSub(string s){
    	int n = s.length();
    	for(int i=0; i<n/2; i++){
    		if(s[i] != s[n-i-1]) return false;
		}
		return true;
	}
	*/
    
    
};


int main(){
	string s;
	cin >> s;
	Solution sol;
	cout << sol.countSubstrings(s) << endl;
}
