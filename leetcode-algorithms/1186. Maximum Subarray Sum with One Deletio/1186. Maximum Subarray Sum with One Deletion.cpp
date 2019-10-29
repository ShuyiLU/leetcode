#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int maximumSum(vector<int>& arr) {
        int n = arr.size();
        if(n == 0) return 0;
        if(n == 1) return arr[0];
        vector<int> endHere(n, 0), startHere(n, 0);
        endHere[0] = arr[0];
        for(int i=1; i<n; i++) endHere[i] = max(endHere[i-1] + arr[i], arr[i]);
        startHere[n-1] = arr[n-1];
        for(int i=n-2; i>=0; i--) startHere[i] = max(startHere[i+1] + arr[i], arr[i]);
        
        int ans = arr[0];
        for(int i=1; i<n-1; i++){
        	ans = max(ans, max(endHere[i-1]+startHere[i+1], endHere[i])) //continuous to i or delete i
		}
        return max(ans, endHere[n-1]);
	}
};
