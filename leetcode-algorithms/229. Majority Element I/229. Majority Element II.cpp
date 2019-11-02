class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int maj1=0, maj2=0, vot1=0, vot2=0;
        int n = nums.size();
        for(int i=0; i<nums.size(); i++){
			if(nums[i] == maj1){
				vot1++;
				continue;
			}  
			   
			if(nums[i] == maj2){
				vot2++;
				continue;
			}			
			   	
        	if(vot1 == 0){
        		vot1++;
        		maj1 = nums[i];
        		continue;
			}

			 
			if(vot2 == 0){
				vot2++;
				maj2 = nums[i];
				continue;
			}			

			
			if(nums[i] != maj1 && nums[i] != maj2){
				vot1--;
				vot2--;
				continue;
			}
		}
		
		vector<int> res;
		int cnt1=0, cnt2=0;
		for(int i=0; i<n; i++){
			if(nums[i] == maj1) cnt1++;
			else if(nums[i] == maj2) cnt2++;
		}
		if(cnt1 > n/3) res.push_back(maj1);
		if(cnt2 > n/3) res.push_back(maj2);
	
		return res;
		
    }
};