#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>

using namespace std;

class Solution {
public:
    int totalFruit(vector<int>& tree) {
    	int len = 1;
    	int max = 0;
    	int mp[40001];
    	memset(mp, sizeof(mp), 0);
    	if(tree.empty()) return 0;
    	int i = 0;
		mp[tree[i]] = 1; 
    	int cnt = 1;
    	int j;
    	for(j=1; j<tree.size(); j++){
    		if(mp[tree[j]] == 0) {
    			cnt++;
    			mp[tree[j]]++;
			}
    		else mp[tree[j]]++;
    		while(cnt > 2){
    			mp[tree[i]]--;
    			if(mp[tree[i]] == 0) {
    				cnt--;
    				i++;
				}
    			else i++;
			}
			len = j-i+1;
			//cout << i << " " << j << endl;
			if(len > max) max = len;
		}
    	//cout << i << " " << j << endl;
		return max;
    }
};

int main(){
	int n;
	cin >> n;
	int a;
	vector<int> v;
	for(int i=0; i<n; i++){
		cin >> a;
		v.push_back(a);
	}
	Solution sol;
	cout << sol.totalFruit(v) << endl;
	return 0;
}
