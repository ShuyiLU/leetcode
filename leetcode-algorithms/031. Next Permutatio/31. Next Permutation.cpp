#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;


class Solution {
public:
	static bool compare (int a, int b){
		return a > b;
	}
	
    void nextPermutation(vector<int>& nums) {
        int len = nums.size();
        int flag = 0;
        for(int i=len-1; i>0; i--){
        	if(nums[i] > nums[i-1]){
        		flag = 1;
        		int min_p = i;
        		for(int j=i; j<len; j++){
        			if(nums[i-1] < nums[j] && nums[j] < nums[min_p]) min_p = j;
				}
				swap(nums[i-1], nums[min_p]);
				sort(nums.begin() + i, nums.end());
				break;
			}
			else continue;
		}
		if(flag == 0){
			sort(nums.begin(), nums.end());
		}
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
	sol.nextPermutation(v);
	for(int i=0; i<n; i++) cout << v[i] << " ";
	return 0;
}
