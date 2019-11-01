class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        if (nums.empty()) return false;
        if (t < 0 || k <= 0) return false;
        map<int, int> mp;
        k++;
        if (nums.size() < k) k = nums.size();
        for(int i=0; i<k-1; i++) mp[nums[i]]++;
        for(int i=0; i<nums.size(); i++){
            if (i + k - 1 < nums.size()) mp[nums[i+k-1]]++;
            int cur = nums[i];
            auto iter = mp.find(cur);
            if (iter->second >= 2) return true;
            if (iter != mp.begin()) {
                --iter;
                if ((long long)cur - iter->first <= t) return true;
                ++iter;
            }
            ++iter;
            if (iter != mp.end()) {
                if ((long long)iter->first - cur <= t) return true;
            }
            mp[cur]--;
            if (mp[cur] == 0) mp.erase(mp.find(cur));
        }
        return false;
    }
};