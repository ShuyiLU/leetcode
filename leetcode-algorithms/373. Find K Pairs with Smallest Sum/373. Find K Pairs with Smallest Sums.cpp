#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

struct st{
	int sum;
	pair<int, int> pa;
	st(int s, pair<int, int> p) : sum(s), pa(p) {}
};

struct cmp{
	bool operator()(st &st1, st &st2){
		return st1.sum < st2.sum;
	}
};

class Solution {
public:
    vector<vector<int> > kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<vector<int> > res;
        vector<int> tmp;
        if(nums1.size() == 0 || nums2.size() == 0 || k == 0) return res;
        priority_queue<st, vector<st>, cmp> q;
        int n = nums1.size();
        int m = nums2.size();
        n = min(k, n);
        m = min(k, m);
        for(int i=0; i<n; i++){
        	for(int j=0; j<m; j++){
        		//tmp.clear();
        		if(q.size() < k){
        			q.push(st(nums1[i]+nums2[j], make_pair(i, j)));	
				}
				else{
					int tmp_sum = nums1[i] + nums2[j];
					if(tmp_sum < q.top().sum){
						q.pop();
						q.push(st(tmp_sum, make_pair(i, j)));
					}
				}
			}
		}
		while(!q.empty()){
			tmp.clear();
			st st1 = q.top();
			q.pop();
			tmp.push_back(nums1[st1.pa.first]);
			tmp.push_back(nums2[st1.pa.second]);
			res.push_back(tmp);
		}
		reverse(res.begin(), res.end());
    	return res;
    }
};

int main(){
	int n, m, k;
	vector<int> n1, n2;
	cin >> n >> m >> k;
	int a; 
	for(int i=0; i<n; i++){
		cin >> a;
		n1.push_back(a);
	}
	for(int i=0; i<m; i++){
		cin >> a;
		n2.push_back(a);
	}
	
	Solution sol;
	vector<vector<int> > res = sol.kSmallestPairs(n1, n2, k);
	for(int i=0; i<res.size(); i++){
		cout << res[i][0] << " " << res[i][1] << endl;
	}
	return 0;
}
