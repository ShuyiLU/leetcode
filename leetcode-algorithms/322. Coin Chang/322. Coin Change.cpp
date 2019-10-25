#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;


class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
    	int n = coins.size();
    	if(n==0) return -1;
        sort(coins.begin(), coins.end());
        if(coins[0] > amount) return -1;
        vector<int> dp(amount+1, -1);
        //dp.resize(amount+1, -1);  //dp[i] : the minimum count when amount = i 
        dp[0] = 0;
        
        for(int i=0; i<=amount; i++){
        	for(int j=0; j<n; j++){
        		if(i-coins[j] < 0) continue;
        		else{
        			if(dp[i-coins[j]] == -1) continue;
        			else{
        				if(dp[i] == -1) dp[i] = dp[i-coins[j]] + 1;
        				else{
        					if(dp[i] > dp[i-coins[j]] + 1)  dp[i] = dp[i-coins[j]] + 1;
						}
					}
				}    		
			}
		}		
		/*for(int i=0; i<=amount; i++) cout << dp[i] << " ";
		cout << endl;*/
		return dp[amount];
    }
};


/*
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
    	if(amount == 0) return 0;
    	int n = coins.size();
    	if(n==0) return -1;
        sort(coins.begin(), coins.end());
        if(coins[0] > amount) return -1;
        vector<int> dp(amount+1, amount+1);
        
        dp[0] = 0;
        for(int i=1; i<=amount; i++){
        	for(int j=0; j<n; j++){
        		if( i >= coins[j] && dp[i-coins[j]] != amount+1){
        			dp[i] = min(dp[i], dp[i-coins[j]]+1);
				}
			}
		}
    	
    	if(dp[amount]<amount+1 && dp[amount]>0) return dp[amount];
    	else return -1;
    	
    }
};

*/


int main(){
	int n;
	cin >> n;
	int a;
	vector<int> v;
	for(int i=0; i<n; i++){
		cin >> a;
		v.push_back(a);
	}
	int am;
	cin >> am;
	Solution sol;
	cout << sol.coinChange(v, am) << endl;
}
