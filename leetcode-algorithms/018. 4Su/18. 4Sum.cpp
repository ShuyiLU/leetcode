#include<iostream>
#include<vector>
#include<set>
#include<algorithm>

using namespace std; 

class Solution {
public:
    vector<vector<int> > fourSum(vector<int>& nums, int t) {
        if(nums.size() < 4) return vector<vector<int> >{};
        int m = nums.size();
        
        set<vector<int> > s;
    	vector<int> tmp;
    	
    	sort(nums.begin(), nums.end());
        
        for(int k = 0; k<m-3; k++){
        	for(int p=k+1; p<m-2; p++){
    			int l = p+1;
    			int r = m-1;
    			while(r<m && l<r){
    				if((nums[l] + nums[r]) == (t - nums[k] - nums[p])){
    					//cout << "1";
    					tmp.push_back(nums[k]);
    					tmp.push_back(nums[p]);
    					tmp.push_back(nums[l]);
    					tmp.push_back(nums[r]);
    					if(s.count(tmp) > 0) tmp.clear();
    					else {
    						s.insert(tmp);
    						tmp.clear();
						}
						l++;
					}
				
					else if(nums[l] + nums[r] < t - nums[k]- nums[p]) l++;
					else if(nums[l] + nums[r] > t - nums[k] - nums[p]) r--;
				
				}
			}
		}
        
        return vector<vector<int> >(s.begin(), s.end());
        
    }
    
    
    vector<vector<int> > threeSum(vector<int>& nums, int t){
    	sort(nums.begin(), nums.end());
    	int m = nums.size();
    	vector<vector<int> > ans;
    	set<vector<int> > s;
    	vector<int> tmp;
    	for(int p=0; p<m-2; p++){
    		int l = p+1;
    		int r = m-1;
    		while(r<m && l<r){
    			if((nums[l] + nums[r]) == (t - nums[p])){
    				//cout << "1";
    				tmp.push_back(nums[p]);
    				tmp.push_back(nums[l]);
    				tmp.push_back(nums[r]);
    				if(s.count(tmp) > 0) tmp.clear();
    				else {
    					s.insert(tmp);
    					tmp.clear();
					}
					l++;
				}
				
				else if(nums[l] + nums[r] < t - nums[p]) l++;
				else if(nums[l] + nums[r] > t - nums[p]) r--;
				
			}
		}
		return vector<vector<int> >(s.begin(), s.end());
	}
    
    
};


int main(){
	int n;
	int tar;
	cin >> n >> tar;
	int a;
	vector<int> t;
	for(int i=0; i<n; i++){
		cin >> a;
		t.push_back(a);
	}
	vector< vector <int> > ans;
	Solution sol;
	ans = sol.fourSum(t, tar);
	
	for(int i=0; i<ans.size(); i++){
		for(int j=0; j<4; j++){
			cout << ans[i][j] << " ";
		}
		cout << endl;
	}
	
	
}
