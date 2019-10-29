#include<iostream>
#include<vector>
#include<map>
#include<algorithm>

using namespace std;

class Solution {
public:

    vector<vector<string> > groupAnagrams(vector<string>& strs) {
    	
        vector<vector<string> > ans; 
        int pos = 0;
        map<string,int> mp;
        if(strs.size() == 0) {
        	if(!ans.empty()) ans.clear();
        	return ans;
		}
		for(int i=0; i<strs.size(); i++){
			string tem = strs[i];
			sort(tem.begin(), tem.end());
			if(mp.count(tem) == 0) {
				mp[tem] = pos;
				pos++;
				ans.push_back(vector<string>{});
			}
			ans[mp[tem]].push_back(strs[i]);
		}
		
		return ans;
		        
		}
              
    
}; 

int main(){
	
}
