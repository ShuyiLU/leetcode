#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
/*
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return 0;
        if(n == 1) return nums[0];
        vector<int> max_a(n, 0);
        vector<int> min_a(n, 0);
        max_a[0] = nums[0];
        min_a[0] = nums[0];
        int res = nums[0];
        for(int i=1; i<n; i++){
        	int tmp1 = max_a[i-1] * nums[i];
        	int tmp2 = min_a[i-1] * nums[i];
        	max_a[i] = max(nums[i], max(tmp1, tmp2));
        	min_a[i] = min(nums[i], min(tmp1, tmp2));
        	res = max(max_a[i], res);
		}
		/*
		for(int i=0; i<n; i++){
			cout << max_a[i] << " " <<  min_a[i] << endl;
		} 
		*//*
		return res;
    }
}; 
*/


class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
		vector<int> s;
		s.push_back(1);
		for(int i=0; i<n; i++){
			if(data[i] != 0){
				s.push_back(s[i] * data[i]);
			}else{
				s.push_back(1);
			}
		} 
		
		int min_neg = 0, max_neg = 0;
		int min_pos = 1, max_pos = 1;
		int ans = nums[0];
		
		for(int i=1; i<= n; i++){
			if(data[i-1] == 0) {
				min_neg = max_neg = 0;
				min_pos = max_pos = 1;
				continue;
			}else if(data[i-1] > 0){
				ans = max(ans, s[i]/min_pos);
			}else{
				if(max_neg != 0) {
					ans = max(ans, s[i]/max_neg);
				}else{
					ans = max(ans, s[i]/max_pos);
				}
			}
			if(s[i] > 0){
				min_pos = min(min_pos, s[i]);
				max_pos = max(max_pos, s[i]);
			}else{
				min_neg = min(min_neg, s[i]);
				max_neg = max(max_neg, s[i]);
			}
		}
		return ans;
		
    }
};

int main(){
	int n;
	cin >> n;
	int a;
	vector<int> v;
	for(int i=0; i<n; i++){
		cin >> a;
		v.push_back(a);
	}
	Solution sol;
	cout << sol.maxProduct(v) << endl;
}
