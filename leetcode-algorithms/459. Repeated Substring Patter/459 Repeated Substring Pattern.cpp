#include<iostream>
#include<cstring>
#include<string.h>

using namespace std;


class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int len = s.length();
        string sub;
        sub.resize(len); 
        int flag;
        for(int i=len/2; i>=1; i--){
        	flag = 0;
        	if(len%i == 0){//i is the possible length of substring
        		int k = len/i;  //k substring in length i combine into  string s.
        		for(int r=0; r<k; r++){
	        		for(int j=0; j<i; j++){
	        			sub[j+r*i] = s[j];
					}	
				}
        		for(int r=0; r<len; r++){
        			if(sub[r] != s[r]) {
	        			flag = 1;
	        			break;	
					}
			   }
				if(flag == 0){
			   		return true;
			   }
			}
		}
	 return false;
    }
};


int main(){
	string s;
	cin >> s;
	Solution solution;
	if(solution.repeatedSubstringPattern(s)) cout << "true" << endl;
	else cout << "false" << endl;
	return 0;
}
