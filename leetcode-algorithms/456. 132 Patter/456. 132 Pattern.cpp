#include<iostream>
#include<vector>

using namespace std;

class Solution {  //ֻ���ҵ���ֵ������ȷ����ֵ�����С��ϵ 
public:
    bool find132pattern(vector<int>& nums) {
        vector<int> dp_order(nums.size(), 0);
        vector<int> dp_reverse(nums.size(), 0);
        for(int i=1; i<nums.size(); i++){
        	if(nums[i] > nums[i-1]) dp_order[i] = dp_order[i-1] + 1;
		}
		
		for(int i=nums.size()-1; i-1>=0; i--){
			if(nums[i-1] > nums[i] ) dp_reverse[i-1] = dp_reverse[i] + 1;
		}
		
		for(int i=0; i<nums.size(); i++){
			if(dp_order[i] != 0 && dp_reverse[i] != 0) return true;
		}
		return false;
    }
};

class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int n = nums.size();
        if(n <= 2) return false;
        int i=0, j=0, k=0;
        while(i<n){
        	while(i<n-1 && nums[i] >= nums[i+1]) i++;  //iֹͣǰ�ݼ�����С   1
        	j = i+1;
        	while(j<n-1 && nums[j] <= nums[j+1]) j++;  //jֹͣǰ������ ����  3
        	k = j+1;
        	while(k<n){
        		if(nums[k] > nums[i] && nums[k] < nums[j]) return true;
        		k++;
			}
			i = j+1;
		}
		return false;
    }
};

class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        stack<int> st;
        int third = INT_MIN;
        for(int i=nums.size()-1; i>=0; i--){
        	if(nums[i] < third) return true;// (1)  1<2
        	else while( !st.empty() && nums[i] > st.top()){ //nums[i]�� ��3)
        		third = st.top(); //third is the max in recently (2),�Ǳ�nums[i]С�ľ����ܴ���� 
        		st.pop();
			}
			st.push(nums[i]);
		}
		return false;
    }
};
