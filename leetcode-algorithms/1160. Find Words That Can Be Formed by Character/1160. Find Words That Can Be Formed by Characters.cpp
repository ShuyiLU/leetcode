#include<iostream>
#include<vector>
#include<cstring>
#include<unordered_map>

using namespace std;

class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        unordered_map<char, int> mp;
        for(int i=0; i<chars.length(); i++){
        	if(mp.count(chars[i]) == 0){
        		mp[chars[i]] = 1;
			}
			else mp[chars[i]]++;
		}
		
		unordered_map<char, int> tmp;
		int flag = 0;	
		int res = 0;
		for(int i=0; i<words.size(); i++){	
			tmp.clear();
			flag = 0;
			for(int j=0; j<words[i].length(); j++){
				if(mp.count(words[i][j]) == 0) {
					flag = 1;
					break;
				}
				if(tmp.count(words[i][j]) == 0) tmp[words[i][j]] = 1;
				else tmp[words[i][j]]++;
				if(tmp[words[i][j]] > mp[words[i][j]]){
					flag = 1;
					break;
				} 
			}
			if(flag == 0) res += words[i].length(); 
		}
		return res;
		
    }
};
