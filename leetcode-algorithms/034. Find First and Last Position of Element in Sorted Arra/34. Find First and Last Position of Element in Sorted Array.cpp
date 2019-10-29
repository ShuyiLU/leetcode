#include<iostream>
#include<vector>

using namespace std; 

class Solution {
private:
	int res1 = -1;
	int res2 = -1;
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> v;
        if(n == 0) {
        	v.push_back(res1);
        	v.push_back(res2);
        	return v;
		}
		
		if(n == 1){
			if(nums[0] == target){
				v.push_back(0);
        		v.push_back(0);
        		
			} 
			
			else{
				v.push_back(res1);
        		v.push_back(res2);	
			}
			return v;
		}
		
		if(n == 2){
			if(nums[0] == target){
				res1 = 0;
				res2 = 0;
			}
			if(nums[1] == target){
				if(nums[0] == target) res2 = 1;
				else{
					res1 = 1;
					res2 = 1;
				}
			}
			v.push_back(res1);
        	v.push_back(res2);
        	return v;
			
		}
		
        int res1 = -1;
        int res2 = -1;
        int l=0;
        int r = nums.size()-1;
        
        pos(nums, l, r, target, res1, res2);
        
        v.push_back(res1);
        v.push_back(res2);
        return v;
    }
    
    void pos(vector<int>& nums, int l, int r, int target, int &res1, int &res2){
    	if(l<r-1){
    	//6	cout << 1 << endl;
    		int mid = (l+r)/2;
    		if(nums[mid] == target){
    			if(res1 == -1){
    				res1 = mid;
    				res2 = mid;
				}
				else{
					if(mid < res1) res1 = mid;
					if(mid > res2) res2 = mid;
				}
				pos(nums, l, mid-1, target, res1, res2);
				pos(nums, mid, r, target, res1, res2);
			}
		
			else if(nums[mid] < target) pos(nums, mid, r, target, res1, res2);
			else pos(nums, l, mid, target, res1, res2);
		}   	
    	else {
    		if(l == r){
    			if(nums[l] == target){
    				if(res1 == -1){
						res1 = l;
						res2 = l;
					}
					else{
						if(l<res1) res1 = l;
						if(l>res2) res2 = l;
					}
    				return;
				}
			}
			else if(l == r-1){
				if(nums[l] == target){
					if(nums[r] == target){
						if(res1 == -1){
							res1 = l;
							res2 = r;
						}
						else{
							if(l<res1) res1 = l;
							if(r>res2) res2 = r;
						}
						
					}
					else{
						if(res1 == -1){
							res1 = l;
							res2 = l;
						}
						else{
							if(l<res1) res1 = l;
							if(l>res2) res2 = l;
						}				
					}
					return;
				}
				else{
					if(nums[r] == target){
						
						if(res1 == -1){
							res1 = r;
							res2 = r;
						}
						else{
							if(r<res1) res1 = r;
							if(r>res2) res2 = r;
						}	
					}
					return;
				}
			}
			else return;
		}   	
	}   
};


int main(){
	int n;
	cin >> n;
	int a;
	vector<int> num;
	for(int i=0; i<n; i++){
		cin >> a;
		num.push_back(a);
	}
	int t;
	cin >> t;
	Solution sol;
	vector<int> re;
	re = sol.searchRange(num,t);
	cout << re[0] << " " <<re[1] << endl; 
}
