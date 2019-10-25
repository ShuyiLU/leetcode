#include<iostream>
#include<vector>

using namespace std;

/*三种状态：
第i天cooldown： cooldown[i] =  sell[i-1]
第i天sell：sell[i] =  max(buy[i-1]+p[i], sell[i-1]) : i-1天买入， i天卖出 或 i-1以前就拥有股票， i-1也可以卖出
第i天buy ： buy[i] = max(cooldown[i-1]-p[i], buy[i-1]) : i-1天是冷冻期， 或 i-1以前就可以买股票 
*/
class Solution {
public:
    int maxProfit(vector<int>& p) {
        int n = p.size();
		if( n == 0 ) return 0;
		vector<int> cooldown(n, 0);
		vector<int> sell(n, 0);
		vector<int> buy(n,0);
		
		sell[0] = 0;
		buy[0] = -p[0];
		
		for(int i=1; i<n; i++){
			cooldown[i] = sell[i-1];
			sell[i] = max(buy[i-1]+p[i], sell[i-1]);
			buy[i] = max(cooldown[i-1]-p[i], buy[i-1]);
		}
		
		return max(max(cooldown[n-1], sell[n-1]), buy[n-1]);
		
    }
};
