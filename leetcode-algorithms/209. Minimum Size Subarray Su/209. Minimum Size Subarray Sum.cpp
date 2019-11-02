class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int i = 0;
        if(nums.size() == 0) return 0;
        //for(int k=0; k<nums.size(); k++) cout << nums[k] << " ";
        //cout << endl;
        int res = INT_MAX;
        int sum = 0;
        for(int j=0; j<nums.size(); j++){
           // cout << i << " " << j << endl;
            sum += nums[j];
            if(sum >= s){
                res = min(res, j-i+1);
                sum -= nums[i];
                i++;
                if(j>=i) {
                   sum -= nums[j];
                    j--;
                }
            }
        }
        int n = nums.size();
        while(i<nums.size()){
            //cout << i << endl;
            if(sum >= s){
                res = min(res, n-i);
                sum -= nums[i];
                i++;
            }
            else break;
        }
        if(res == INT_MAX) return 0;
        return res;
    }
};
