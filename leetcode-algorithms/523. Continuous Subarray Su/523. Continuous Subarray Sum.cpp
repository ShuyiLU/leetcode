class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        if (nums.size()<2) return false;
        for (int i=1; i<nums.size(); i++) if (!nums[i]&&!nums[i-1]) return true;
        if (!k) return false;
        int sum=0;
        unordered_map<int, int> m;
        m[sum]=0;
        for (int i=0; i<nums.size(); i++) {
            sum=(sum+nums[i])%k;
            if (!m.count(sum)) m[sum]=i+1;
            else if (i+1-m[sum]>1) return true;
        }
        return false;
    }
};
