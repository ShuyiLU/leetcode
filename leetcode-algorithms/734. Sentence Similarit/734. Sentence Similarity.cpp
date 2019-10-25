#include<iostream>
#include<unordered_map>
#include<vector>
#include<cstring>
#include<set>

using namespace std;

class Solution {
public:
    bool areSentencesSimilar(vector<string>& words1, vector<string>& words2, vector<pair<string, string> > pairs) {
        // unordered_map<string, string> mp;
        // unordered_map<string, string> :: iterator it;
        set<pair<string, string> > mp;
        pair<string, string> tmp;
        pair<string, string> toFind;
        for(int i=0; i<pairs.size(); i++){
        	tmp = pairs[i];
        	mp.insert(tmp);
        	mp.insert(make_pair(tmp.second, tmp.first));
		}
		if(words1.size() != words2.size()) return false;
		else{
			for(int i=0; i<words1.size(); i++){
				if(words1[i] == words2[i]) continue;
				else{
					toFind = make_pair(words1[i], words2[i]);
					//it = mp.find(words1[i]);
					if(mp.count(toFind) == 0) return false;
					else continue;	
				}
				
			}
			return true;
		}
    }
};


