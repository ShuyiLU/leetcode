#include<iostream>
#include<vector>
#include<map>
#include<cstring>

using namespace std;

class Solution {
private:
	map<string, bool> mp;
public:
    bool canWin(string s) {
        int len = s.length();
        if(len < 2) return false;
        if(mp[s] == true) return true;
        string tmp = s;
        for(int i=1; i<tmp.size(); i++){
        	if(tmp[i] == tmp[i-1] && tmp[i] == '+'){
        		tmp[i] = '-';
        		tmp[i-1] = '-';
        		if(!canWin(tmp)) {
        			mp[s] = true;  //new string is unavailable, thus s can ensure win 
        			return true;
				}
                tmp[i] = '+';
                tmp[i-1] = '+';
			}
		}
		return false;
    }
    
};
