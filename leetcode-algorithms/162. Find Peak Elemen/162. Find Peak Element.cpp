#include<iostream>
#include<vector>

using namespace std; 

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int l=0;
        int r=nums.size()-1;
        while(l<=r){
        	int mid = (l+r)/2;
        	cout << l << " " << r << " " << mid <<endl;
        	if((mid == 0 || nums[mid-1]<nums[mid]) && (mid == nums.size()-1 || nums[mid]>nums[mid+1])) return mid;
        	else if(nums[mid+1] > nums[mid]) l = mid+1;
        	else r=mid-1;
		}
    }
};

int main(){
	int n;
	vector<int> v;
	int a;
	cin >> n;
	for(int i=0; i<n; i++){
		cin >> a;
		v.push_back(a);
	}
	Solution sol;
	int ans = sol.findPeakElement(v);
	cout << "ans :" << ans << endl;
}
