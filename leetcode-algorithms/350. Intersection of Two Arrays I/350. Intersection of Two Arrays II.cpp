class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        int n=nums1.size(), m=nums2.size();
        for (int i=0, j=0; i<n&&j<m; ) {
            while (nums1[i]<nums2[j]&&i<n) i++;
            if (i==n) break;
            while (nums2[j]<nums1[i]&&j<m) j++;
            if (j==m) break;
            while (nums1[i]==nums2[j]&&i<n&&j<m) {
                ans.push_back(nums1[i]);
                i++, j++;
            }
        }
        return ans;
    }
};
