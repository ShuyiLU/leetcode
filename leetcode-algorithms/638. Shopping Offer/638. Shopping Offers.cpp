#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

/*
class Solution {
public:
    int shoppingOffers(vector<int>& price, vector<vector<int> >& special, vector<int>& needs) {
        return dfs(price, special, needs);
    }
    
    bool isValid(vector<int> s, vector<int> need){
    	int n = need.size();
    	for(int i=0; i<n; i++){
    		if(s[i] > need[i]) return false;
		}
		return true;
	}
	
	int dfs(vector<int>& price, vector<vector<int> >& special, vector<int>& needs){
		int minprice = 0;
		int len = needs.size();
		for(int i=0; i<len; i++){
			minprice += price[i] * needs[i];
		}
		
		
		int n = special.size();
		for(int i=0; i<n; i++){
			int tmp = -1;
			vector<int> v;
			
			if(isValid(special[i], needs)){
				for(int j=0; j<len; j++){
					v.push_back(needs[j] - special[i][j]);
				}
				tmp = special[i][len] + dfs(price, special, v);
			}
			
			if(tmp != -1){
				minprice = min(minprice, tmp);  //each special offer special[i] have minprice;
			}
			
		}
		
		return minprice;
		
		
	}
    
    
};
*/

class Solution {
public:
    int shoppingOffers(vector<int>& price, vector<vector<int> >& special, vector<int>& needs) {
        int n = needs.size();
        int res = 0;
        for(int i=0; i<n; i++){
        	res += price[i] * needs[i];
		}
		
		for(int i=0; i<special.size(); i++){
			int flag = 1;
			for(int j=0; j<n; j++){
				if(needs[j] < special[i][j]) flag = 0;
				needs[j] = needs[j] - special[i][j];
			}
			
			if(flag) res = min(res, shoppingOffers(price, special, needs)+special[i].back()); //leave items need + price use in this offer
			for(int j=0; j<n; j++) needs[j] = needs[j] + special[i][j];
			
		}
		
		return res;
		
    }
};

int main(){
}
