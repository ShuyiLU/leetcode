class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();
        if(n == 3) return nums[0] + nums[1] + nums[2];
        sort(nums.begin(), nums.end());
        int min = nums[0] + nums[1] + nums[2];
        for(int i=0; i<=n-3; i++){
            int l = i+1;
            int r = n-1;
            int tmp = nums[i];
            while(l < r){
                tmp += nums[l] + nums[r];
                if(abs(target-tmp) < abs(target-min)) min = tmp;
                if(tmp<target) l++;
                else r--;
                tmp = nums[i];
            }
        }
        return min;
        
    }
};









class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();
        if(n == 3) return nums[0] + nums[1] + nums[2];
        sort(nums.begin(), nums.end());
        map<int, int> mp;
        for(int i=0; i<=n-3; i++){
            int l = i+1;
            int r = n-1;
            int tmp = nums[i];
            while(l < r){
                tmp += nums[l] + nums[r];
                if(mp.count(i) == 0 || abs(target-tmp) < abs(target-mp[i])){
                    mp[i] = tmp;
                }
                if(tmp < target) l++;
                else r--;
                tmp = nums[i];
            }
        }
        map<int, int> :: iterator it;
        int min = (*mp.begin()).second;
        for(it = mp.begin(); it!= mp.end(); it++){
          //  cout << (*it).first << " " << (*it).second << endl;
            if(abs(target-(*it).second) < abs(target-min)) min = (*it).second;
        }
        return min;
    }
};
