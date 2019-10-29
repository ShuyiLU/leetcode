#include<iostream>
#include<vector>
#include<map>

using namespace std;


/*
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        if(n == 0) return 0;
        if(n == 1){
        	if(nums[0] == k) return 1;
        	else return 0;
		}
		int cnt = 0;
		vector<vector<int> > v; //v[i][j]: i~j's sum
		v.resize(n);
		for(int i=0; i<n; i++) v[i].resize(n);
		for(int i=0; i<n; i++){
			for(int j=0; j<n; j++){
			//	cout << i << " " << j << endl;
				if(i>j) v[i][j] = -1;
				else if(i == j) {
					v[i][j] = nums[i];
					if(v[i][j] == k) cnt++;
				}
				else{
					v[i][j] = v[i][j-1] + nums[j];
					if(v[i][j] == k) cnt++;
				}
			}
		}
		
		return cnt;	
		
    }
};


*/

/*
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        if(n == 0) return 0;
        if(n == 1){
        	if(nums[0] == k) return 1;
        	else return 0;
		}
		int cnt = 0;
		
		vector<int> sum(n); //sum[i]: 0~i th's sum
		
		for(int i=0; i<n; i++){
			if(i == 0) sum[i] = nums[0];
			else sum[i] = sum[i-1] + nums[i];
		}
		
		for(int i=0; i<n; i++){
			for(int j=i; j<n; j++){
				if(j<j){
					continue;
					//3cout << "a" << endl;
				} 
				else if(i == j){
					if(sum[i] == k){
					//	cout << i << " " << j << endl;	
						cnt++;
					} 
			
				} 
				else{
					if(sum[j] - sum[i] == k) {
					//	cout << i << " " << j << endl;
						cnt++;
					}
					
				}
			}
		}
		
		return cnt;
    }
};
*/

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        if(n == 0) return 0;
        if(n == 1){
        	if(nums[0] == k) return 1;
        	else return 0;
		}
		int cnt = 0;
		
		int sum = 0;
		map<int, int> m;
		m[0] = 1;
		for(int i=0; i<n; i++){
			sum += nums[i];
			cnt += m[sum-k];
			m[sum] += 1;
		}
		return cnt;
    }
};

int main(){
	int n;
	int k;
	cin >> n >> k;
	int a;
	vector<int> v;
	for(int i=0; i<n; i++){
		cin >> a;
		v.push_back(a);
	}
	Solution sol;
	cout << sol.subarraySum(v, k) << endl;
}
