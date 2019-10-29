#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
    	int res = 0;
    	if(nums.size() == 0) return res;
    	int n = nums.size();
    	vector<int> sum(n, 0);
    	sum[0] = nums[0];
    	int ma = nums[0];
        for(int i=1; i<n; i++){
        	ma = max(ma, nums[i]);
        	sum[i] = sum[i-1] + nums[i];
		}
		int l = ma;
		int r = sum[n-1];
        //cout << l << " " << r << " " << endl;
		while(l+1<r){
            //cout << l << " " << r << " " << endl;
			int mid = l + (r-l)/2;
			if(canSplit(nums, mid, m)) r = mid;
			else l = mid;
		}
		res = r;
		return res;
    }
    
    bool canSplit(vector<int>& nums, int t, int m){
    	int cnt = 0; //0~m-1
    	int sum = 0;
    	for(int i=0; i<nums.size(); i++){
    		if(sum + nums[i] <= t){
    			sum += nums[i];
			}
			else{
				cnt++;
				sum = nums[i];
			}
			if(cnt >= m) return false;
		}
		return true;
	} 
    
};
