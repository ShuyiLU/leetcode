class Solution {
public:
    int maxSubArrayLen(vector<int>& nums, int k) {
        int sum=0;
        unordered_map<int, int> m;
        int ml=0;
        for (int i=0; i<nums.size(); i++) {
            sum+=nums[i];
            if (sum==k) ml=i+1;
            else {
                if (m.count(sum-k)) ml=max(ml, i-m[sum-k]);
            }
            if (!m.count(sum)) m[sum]=i;
        }
        return ml;
    }
};