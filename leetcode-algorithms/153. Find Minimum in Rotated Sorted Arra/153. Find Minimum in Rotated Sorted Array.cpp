#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];
        if(n == 2) return min(nums[0], nums[1]);
        int l = 0, r = n-1;
        int res;
        while(l <= r){
        	int mid = (l+r)/2;
        	if(mid-1>=0 && mid+1<n){
        		if(nums[mid] <= nums[mid-1] && nums[mid] <= nums[mid+1]){
        			res = nums[mid];
        			break;
				}
				if(nums[mid] > nums[n-1]){
					l = mid+1;
				}
				else if(nums[mid] < nums[0]){
					r = mid-1;
				}
                else{
                    res = nums[0];
                    break;
                }
			}
			else if(mid-1<0){
				res = min(nums[0], nums[1]);
				break;
			}
			else if(mid+1>=n){
				res = min(nums[n-1], nums[n-2]);
				break;
			}
		}
		return res;
    }
};
