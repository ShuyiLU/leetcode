#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>
#include<map>

using namespace std; 

class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        map<char, char> mp;
        int flag;
        vector<string> res;
        set<char> s1, s2;
        for(int i=0; i<words.size(); i++){
        	string cur = words[i];
        	if(cur.length() != pattern.length()) continue;
        	mp.clear();
            s1.clear();
            s2.clear();
        	flag = 0;
        	for(int j=0; j<cur.length(); j++){
        		if(mp.count(pattern[j]) == 0 ){
        			mp[pattern[j]] = cur[j];
                    s1.insert(pattern[j]);
                    s2.insert(cur[j]);
				}
				else{
					if(mp[pattern[j]] != cur[j]) {
                        flag = 1;
                        break;
                    }
				}
			}
			if(flag == 0 && s1.size() == s2.size()) res.push_back(cur);
		}
		return res;
    }
};
