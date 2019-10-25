class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        if (nums.empty()) return 0;
        int ans=1, l=0;
        for (int i=1; i<nums.size(); i++) {
            if (nums[i]<=nums[i-1]) l=i;
            ans=max(ans, i-l+1);
        }
        return ans;
    }
};