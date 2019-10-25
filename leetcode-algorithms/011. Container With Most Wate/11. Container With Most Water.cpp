#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>

using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int l = 0;
        int r = n-1;
        int max = 0;
        int tmp = 0;
        while(l<r){
        	tmp = (r-l) * min(height[l], height[r]);
        	if(tmp > max) max = tmp;
        	if(height[l] < height[r]) l++;
        	else r--;
		}
		return max;
    }
};

int main(){
}
