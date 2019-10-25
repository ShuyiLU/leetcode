#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int numTrees(int n) {
    	vector<int> v;
    	v.resize(n+1, 0);
    	
        if(n == 0) return 0;
        if(n == 1) return 1;
        if(n == 2) return 2;
        if(n == 3) return 5;
        v[0] = 1;
        v[1] = 1;
        v[2] = 2;
        v[3] = 5;
        for(int i=4; i<=n; i++){
        	for(int j=0; j<i; j++){
        		v[i] = v[i] + v[j] * v[i-1-j];
			}
		}
		return v[n];
    }
};

int main(){
	int n;
	cin >> n;
	Solution sol;
	cout << sol.numTrees(n) << endl;
}
