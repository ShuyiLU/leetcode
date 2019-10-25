#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        int sum1, sum2;
        
        if(n == 0) return 0;
        
        vector<int> f (n, 0);
        
        for(int i=0; i<n; i++){
        	if(i == 0) f[i] = nums[0];
        	else if( i == 1) f[i] = max(nums[0], nums[1]);
        	else f[i] = max(f[i-1], f[i-2]+nums[i]);
		}
		
		return f[n-1];
    }
};


int main(){
	int n ;
	cin >> n;
	int a;
	vector<int> v;
	for(int i=0; i<n; i++){
		cin >> a;
		v.push_back(a);
	}
	Solution sol;
	cout << sol.rob(v) << endl;
}
