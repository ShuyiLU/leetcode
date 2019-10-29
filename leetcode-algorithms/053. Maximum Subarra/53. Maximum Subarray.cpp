#include<iostream>
#include<vector>
using namespace std;

class Solution {
private:
	int FindCrossMax(vector<int> A, int l, int mid, int h){
		int leftsum = A[mid];
		int rightsum = A[mid+1];
		int sum = 0;
		for(int i=mid; i>=l; i--){
			sum = sum + A[i];
			if(sum > leftsum){
				leftsum = sum;
				//left = i;
			}
		}
		sum = 0;
		for(int j=mid+1; j<=h; j++){
			sum = sum + A[j];
			if(sum > rightsum){
				rightsum = sum;
			}
		}
		return leftsum+rightsum;
	}
	
	int FindMax(vector<int> A, int l, int h){
		//int sum;
		int sum1,sum2,sum3;
		if(l == h) {
			return A[l];
		}
		else{
			int mid = (l+h)/2;
			sum1 = FindMax(A, l, mid);
			sum2 = FindMax(A, mid+1, h);
			sum3 = FindCrossMax(A, l, mid, h);
			if(sum1 >= sum2 && sum1 >= sum3) return sum1;
			else if(sum2 >= sum1 && sum2 >= sum3) return sum2;
			else return sum3;
		}
	}	
	
public:
    int maxSubArray(vector<int>& nums) {
        int len = nums.size();
        return FindMax(nums, 0, len-1);
    }
};
