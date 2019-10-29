#include<iostream>
#include<vector>

using namespace std; 

class Solution {
public:
    int shipWithinDays(vector<int>& weights, int D) {
        int m = max_element(weights, weights+weights.size());
    	int sum = 0;
    	for(int i=0; i<weights.size(); i++) sum+=weights[i];
        int low = m, high = sum;
        int ans = high;
        while(low < high){
        	int mid = (low+high)/2;  //capacity
        	int day = 1;
        	int tmp = 0;
        	int k =0;
        	while(k<weights.size()){
        		tmp += weights[k];
        		if(tmp > mid)
        		{
        			tmp = weights[k];
        			day++;
				}
				k++;
			}
			if(day <= D){
				high = mid;
				ans = min(ans, mid);
			}
			else low = mid + 1;
			
		}
		return ans;
    }
};
