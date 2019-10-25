#include<iostream>
#include<string>
#include<map>

using namespace std;


class Solution {
public:
    int firstUniqChar(string s) {
    	map<char, int> mp;
    	int len = s.length();
    	for(int i=0; i<len; i++){
    		if(mp.count(s[i])==0) mp[s[i]] = 1;
    		else mp[s[i]] += 1;
		}
		for(int i=0; i<len; i++){
			if(mp[s[i]] == 1) return i;
			else continue;
		}
    	return -1;
    	  	
        
    }
};
