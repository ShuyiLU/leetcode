#include<iostream>
#include<vector>
#include<set>

using namespace std;

class Solution {
public:
    vector<vector<int> > subsets(vector<int>& nums) {
    	int n = nums.size();
    	if(n == 0) return vector<vector<int> > {};
    	
    	vector <vector<int> > s;
    	vector<int> tmp;
    	
    	s.push_back(tmp);
    	
    	backtrack(nums, s, tmp, n, 0);
	
		return s;
        
    }
    
    void backtrack(vector<int>& nums, vector<vector<int> >& s, vector<int>& tmp, int n, int i){
    	//set<vector<int> > s;
    	//vector<int> tmp;
    	
    	if(i == n){
    		return;
		}
    	
    	for(int j=i; j<n; j++){
    		tmp.push_back(nums[j]);
    		s.push_back(tmp);
    		backtrack(nums, s, tmp, n, j+1);
    		tmp.pop_back();
		}
    	
    	
	}
    
  
};

int main(){
	
}
