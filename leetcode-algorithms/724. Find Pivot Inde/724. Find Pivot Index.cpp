#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        if(nums.size() == 0) return -1;
        int flag = 0;
        vector<int> sum_l;
        vector<int> sum_r;
        //sum_l.push_back(0);
        //sum_r.push_back(0);
        int tmp_l = 0;
        int tmp_r = 0;
    	for(int i=0; i<nums.size(); i++) tmp_r += nums[i];
    //	cout << tmp_l << " " << tmp_r << endl;
        for(int i=0; i<nums.size(); i++){
        	if(i==0) sum_l.push_back(tmp_l);
        	else{
        		tmp_l = tmp_l + nums[i-1];
        		sum_l.push_back(tmp_l);
			}       	
        	tmp_r = tmp_r - nums[i];
        	sum_r.push_back(tmp_r);
		}
		for(int i=0; i<sum_l.size(); i++){
			if(sum_l[i] == sum_r[i]) return i;
		}
		return -1;
    }
};

int main(){
	vector<int> v;
	int n;
	cin >> n;
	int k;
	for(int i=0; i<n; i++){
		cin >> k;
		v.push_back(k);
	}
	Solution sol;
	cout << sol.pivotIndex(v) << endl;
}
