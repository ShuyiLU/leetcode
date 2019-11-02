class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
		if(k <= 1) return 0;
        int i=0;
		int tmp = 1;
		int res = 0;
		for(int j=0; j<nums.size(); j++){
			tmp = tmp*nums[j];
			while(tmp>=k){
				tmp = tmp/nums[i];
				i++;	
			}
			res = res + j - i + 1; //每次新增包含nums[j]的子数组个数
		}
		return res;
    }
};
