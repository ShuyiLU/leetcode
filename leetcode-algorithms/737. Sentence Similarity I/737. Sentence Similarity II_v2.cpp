#include<iostream>
#include<vector>
#include<cstring>
#include<map>
#include<set>

using namespace std;

class Solution {
public:
	vector<int> fa;
	int findFa(int x){
		if(x != fa[x]) fa[x] = findFa(fa[x]);
		return fa[x];
	}
	
	void merge(int x, int y){
		int fa_x = findFa(x);
		int fa_y = findFa(y);
		else fa[fa_y] = fa_x;
	}
	
	
    bool areSentencesSimilarTwo(vector<string>& words1, vector<string>& words2, vector<vector<string>>& pairs) {
        fa.resize(pairs.size()*2);
        map<string, int> mp;
        int index = 0;
        if(words1.size() != words2.size()) return false;
        for(int i=0; i<pairs.size()+1; i++) fa[i] = i;
        for(int i=0; i<pairs.size(); i++){
        	string st1 = pairs[i][0];
        	string st2 = pairs[i][1];
        	if(mp.count(st1) == 0){
        		mp[st1] = index;
        		index++;
			}
			if(mp.count(st2) == 0){
				mp[st2] = index;
				index++;
			}
			merge(mp[st1], mp[st2]);
		}
        map<string, int> :: iterator it;
       // for(it = mp.begin(); it!= mp.end(); it++) cout << (*it).first << " " << (*it).second << " " << findFa(mp[(*it).first]) << endl;
        //for(int i=0; i<7; i++) cout << fa[i] << " " ;
        //cout << endl;
		for(int i=0; i<words1.size(); i++){
			if(words1[i] == words2[i]) continue;
			else{
				if(mp.count(words1[i]) == 0 || mp.count(words2[i]) == 0) return false;
				if(findFa(mp[words1[i]]) != findFa(mp[words2[i]])) return false;
			}
		}
        return true;
    }
};
