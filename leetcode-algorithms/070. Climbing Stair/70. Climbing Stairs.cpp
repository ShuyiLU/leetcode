#include<iostream>
#include<vector> 

using namespace std;

class Solution {
public:
    int climbStairs(int n) {
    	if(n <= 2) return n;
        else {
			vector<int> v;
			v.resize(n+1);
			v[0] = 0;
			v[1] = 1;
			v[2] = 2;
			for(int i=3; i<=n; i++){
				v[i] = v[i-1] + v[i-2];
			}
			return v[n];
		} 
		
    }
};

int main(){
	int n;
	cin >> n;
	Solution sol;
	cout << sol.climbStairs(n) << endl;
}
