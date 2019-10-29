#include<iostream>
#include<vector>

using namespace std; 

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        if(n > m) return findMedianSortedArrays(nums2, nums1);  //previous always smaller
        
        
        int L1, L2, R1, R2, c1, c2, low = 0, high = 2*n; //nums1:2n, nums2:2m
        //L1: max of cut1 (c1) left
        //c1: # in cut1
        
        //L = nums[(c-1)/2]
        //R = nums[c/2];
        
        while(low <= high){
        	c1 = (low + high)/2;
        	c2 = m + n - c1;
        	if(c1 == 0) L1 = INT_MIN;
        	else L1 = nums1[(c1-1)/2];
        	
        	if(c1 == 2*n) R1 = INT_MAX;
        	else R1 = nums1[c1/2];
        	
        	if(c2 == 0) L2 = INT_MIN;
        	else L2 = nums2[(c2-1)/2];
        	
        	if(c2 == 2*m) R2 = INT_MAX;
        	else R2 = nums2[c2/2];
        	
        	if(L1 > R2) high = c1 -1;  // c1 has too much element
        	else if(L2 > R1) low = c1 + 1;
        	else break;
        	
        	
		}
		return (max(L1, L2) + min(R1, R2)) / 2.0;
        
    }
};
