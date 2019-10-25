#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    vector<int> countBits(int n) {

    	vector<int> v(n+1, 0);
    	for(int i=0; i<=n; i++){
    		v[i] = v[i>>1] + i%2;
		}
        return v;
    }
};

int main(){
	int n;
	cin >> n;
	Solution sol;
	vector<int> v = sol.countBits(n);
	for(int i=0; i<v.size(); i++) cout << v[i] << " ";
}
