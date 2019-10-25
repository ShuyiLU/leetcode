#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        int maj = 0;
        int vote = 0;
        for(int i=0; i<n; i++){
        	if(vote == 0){
        		maj = nums[i];
        		vote++;
        		continue;
			}
			
			if(nums[i] == maj){
				vote++;
			}
			else{
				vote--;
			}
			

			
		}
			int cnt = 0;
			for(int i=0; i<n; i++){
				if(nums[i] == maj) cnt++;
			}
			if(cnt > n/2) return maj;
			else return -1;
    }
}; 
