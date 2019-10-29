class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        n=nums.size();
        dfs(nums, 0);
        return ans;
    }
private:
    vector<vector<int>> ans;
    vector<int> tmp;
    int n;
    void dfs(vector<int>& nums, int sta) {
        if (sta==n) {
            ans.push_back(tmp);
            return;
        }
        int number=nums[sta], cnt=0;
        int cur=sta;
        while (cur<n&&nums[cur]==number) {cur++; cnt++;}
        for (int i=0; i<=cnt; i++) {
            dfs(nums, cur); tmp.push_back(number);
        }
        for (int i=0; i<=cnt; i++) tmp.pop_back();
    }
};
