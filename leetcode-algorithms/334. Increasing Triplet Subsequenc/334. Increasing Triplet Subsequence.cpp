#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        if(nums.size() < 3) return false;
		int min1=INT_MAX, min2=INT_MAX;
        for(int i=0; i<nums.size(); i++){
        	if(nums[i] <= min1) min1 = nums[i];	
  			else if( nums[i] <= min2) min2 = nums[i]; // else if: nums[i] must > min1
  			else return true;
		}
		return false;
    }
}; 

int main(){
	int n;
	cin >> n;
	int a;
	vector<int> v;
	for(int i=0; i<n; i++)
	{
		cin >>a;
		v.push_back(a);
	}
	Solution sol;
	if(sol.increasingTriplet(v)) cout << "t" << endl;
	else cout << "f" <<endl;
}
