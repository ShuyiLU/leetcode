#include<iostream>
#include<vector>

using namespace std; 

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return vector<int> {};
        vector<int> s1(n, 1);
        vector<int> s2(n, 1);
        for(int i=0; i<n; i++){
        	if(i == 0) s1[i] = 1;
        	else{
        		s1[i] = s1[i-1] * nums[i-1];
			}
		}
        
        for(int i=n-1; i>=0; i--){
        	if(i == n-1) s2[i] = 1;
        	else{
        		s2[i] = s2[i+1] * nums[i+1];
			}
		}
		
		for(int i=0; i<n; i++) nums[i] = s1[i] * s2[i];
		return nums;
        
        
    }
};

int main(){
	int n;
	cin >> n;
	vector<int> v;
	int a;
	for(int i=0; i<n; i++){
		cin >> a;
		v.push_back(a);
	}
	Solution sol;
	vector<int> res = sol.productExceptSelf(v);
	for(int i=0; i<n; i++) cout << res[i] << " " ;
	
}
