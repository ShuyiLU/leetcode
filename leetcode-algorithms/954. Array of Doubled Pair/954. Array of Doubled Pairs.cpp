#include<iostream>
#include<vector>
#include<map>
#include<algorithm>

using namespace std; 

class Solution {
public:
    bool canReorderDoubled(vector<int>& A) {
        map<int, int> mp;
        int len = A.size();
        if(len % 2 == 1) return false;
        sort(A.begin(), A.end());
        for(int i=0; i<A.size(); i++) mp[A[i]]++;
        for(int i=0; i<A.size()/2; i++){
        	mp[A[i]]--;
        	if(mp[A[i]*2] > 0){
        		mp[A[i]*2]--;
			}
			else if(mp[A[i]]/2 > 0){
				mp[A[i]/2]--;
			}
			if(mp[A[i]*2] == 0 || mp[A[i]/2] == 0 || mp.count(A[i]*2) == 0 || mp.count(A[i]/2) == 0) return false;
		}
        return true;
    }
};
