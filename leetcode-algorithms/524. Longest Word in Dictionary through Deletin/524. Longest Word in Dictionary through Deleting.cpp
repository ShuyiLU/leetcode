#include<iostream>
#include<cstring>
#include<vector>

using namespace std;

class Solution {
public:
    string findLongestWord(string s, vector<string>& d) {
        string ans = "";
        for(int i=0; i<d.size(); i++){
        	int l1 = ans.length();
			int l2 = d[i].length();
			if(l1 > l2 || (l1==l2 && ans<d[i])) continue;
			int one=0, two=0;
			while(one<s.length() && two<d[i].length()){
				if(s[one] == d[i][two]) two++;
				one++;
			}	
			if(two == d[i].length()) ans = d[i];
		}
        
        return ans;
    }
};
