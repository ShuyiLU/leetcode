#include<iostream>
#include<vector>

using namespace std; 


class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) 
    {
        int res=0;
        int n=days.size();
        vector<int> dp(366,0);
        for(int i=1;i<=days[n-1];i++)
        {
            if(find(days.begin(),days.end(),i)==days.end())
            {
                dp[i]=dp[i-1];
                cout << i << endl;
            }
            else
            {
                if(i-7>=0)
                {
                    dp[i]=min(dp[i-1]+costs[0],dp[i-7]+costs[1]);
                    if(i-30>=0)
                    {
                        dp[i]=min(dp[i],dp[i-30]+costs[2]);
                    }
                    else
                    {
                        dp[i]=min(dp[i],dp[0]+costs[2]);
                    }
                }
                else
                {
                    dp[i]=min(dp[i-1]+costs[0],dp[0]+costs[1]); //第i天买一张单票，或者在第0天买一张7天票 
                    dp[i]=min(dp[i],dp[0]+costs[2]); //以上的最小值和在第0天买一张30天的票 
                }
            }
        }
        return dp[days[n-1]];        
    }
};
