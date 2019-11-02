class Solution {
public:
    bool canPartition(vector<int>& nums) {
        //sort(nums, nums.size());
        int sum = 0;
        int n = nums.size();
        for(int i=0; i<n; i++) sum += nums[i];
        if(sum%2 == 1) return false;
        vector<bool> dp(sum+1, 0);
        dp[0] = 1;
        for(int i=0; i<n; i++){
            for(int j=sum; j>=nums[i]; j--){
                dp[j] = dp[j] || dp[j-nums[i]];
            }
            if(dp[sum/2]) return true;
        }
       return false;
    }
};
