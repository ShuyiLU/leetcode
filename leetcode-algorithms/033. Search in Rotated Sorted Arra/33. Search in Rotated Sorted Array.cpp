#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
  		int ans = -1;
		if(nums.size() == 0) return ans;
		if(nums.size() == 1) {
			if(nums[0] == target) return 0;
			else return ans;
		} 
		if(nums.size() == 2){
			if(nums[0] == target) return 0;
			else if(nums[1] == target) return 1;
			else return ans;
		}
		int n = nums.size();
		int l = 0;
		int r = n-1;
		
		while(l<r && r<n){
			int mid = (l+r)/2;
			if(nums[mid] == target) {
				ans = mid;
				break;
			}
			else{
				if(l == r - 1) {
					if(target == nums[l]) {
						ans = l;
						break;
					}
					else if(target == nums[r]) {
						ans = r;
						break;
					}
					else break;
				}
				if(nums[mid-1] <= nums[mid] && nums[mid] <= nums[mid+1]){
					if(nums[mid] >= nums[0]){
						//left ordered,right unordered
						if(target >= nums[l] && target < nums[mid]){
							r = mid;
						//	cout << "a" << " " << l <<" " << r << endl;
						}
						
						else {
							l = mid;
						//	cout << "b" << " " << l <<" " << r << endl;
						}	
					}
					
					else{
						//left unordered, right ordered
						if(target > nums[mid] && target <= nums[r]){
							l = mid;
						//	cout << "c" << " " << l <<" " << r << endl;
						}
						else{
							r = mid;
						//	cout << "d" << " " << l <<" " << r << endl;
						}
						
					}	
				}
				
				else{ // uncontinuous at mid
					if(target >= nums[l]){
						r = mid;
					//	cout << "e" << " " << l <<" " << r << endl;
					}
					else{
						l = mid;
					//	cout << "f" << " " << l <<" " << r << endl;
					}
					
				}				
				
				
			}
		}
	//	cout << l <<" " << r << endl;
	/*
		if(l == r-2){
			if(nums[l] == target) return l;
			else if(nums[r] == target) return r;
			else if(nums[l+1] == target) return l+1;
			else return ans;
		}
		
		if(l == r-1){
			if(nums[l] == target) return l;
			else if(nums[r] == target) return r;
			else return ans;
		}
		
		if(l == r){
			if(nums[l] == target) return l;
			else return ans;
		}
		*/
		return ans;
    }
};


int main(){
	int n;
	cin >> n;
	int t;
	cin >> t;
	int a;
	vector<int> v;
	for(int i=0; i<n; i++){
		cin >> a;
		v.push_back(a);
	}
	Solution sol;
	cout << sol.search(v, t) << endl;
}
