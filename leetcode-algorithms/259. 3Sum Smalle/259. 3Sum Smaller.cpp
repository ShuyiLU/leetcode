class Solution {
public:
    int threeSumSmaller(vector<int>& nums, int target) {
        int n=nums.size();
        if (n<3) return 0;
        int ans=0;
        sort(nums.begin(), nums.end());
        for (int j=n-2; j>0; j--) {
            int k;
            for (int i=0; i<j; i++) {
                int t=target-nums[i]-nums[j]; // nums[k]<t
                if (i==0) {
                    k=lower_bound(nums.begin()+j+1, nums.end(), t)-nums.begin()-1; // nums[k] is the last number < t
                    ans+=(k-j);
                }
                else {
                    while (nums[k]>=t&&k>j) k--; ans+=(k-j);
                }
            }
        }
        return ans;        
    }
};