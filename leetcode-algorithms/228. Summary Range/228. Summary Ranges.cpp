#include<vector>
#include<iostream>
#include<string>

using namespace std;

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
    	if(nums.size() == 0) return vector<string>{};
        vector<string> v;
        string tmp;
        for(int i=0; i<nums.size(); i++){
        	if(i == 0) {
        		tmp = tmp + to_string(nums[i]);
        		continue;
			}
						       	
        	if(nums[i] == nums[i-1] + 1){
        		continue;
			}
			else{
				if(tmp == to_string(nums[i-1])) v.push_back(tmp);
				else{
					tmp = tmp + "->"  + to_string(nums[i-1]);
					v.push_back(tmp);
				}
				
				tmp = to_string(nums[i]); 
			}
			
		}
		
		if(tmp != "") v.push_back(tmp);
		if(nums[nums.size()-1] == nums[nums.size()-2] + 1) v[v.size()-1] = v[v.size()-1] + "->" + to_string(nums[nums.size()-1]);
		//cout << v.size() << endl;		
		
        return v;
        
    }
};

int main(){
	
//	int b = 1;
//	cout << char(b + '0' )<< endl;
	
	int n;
	cin >> n;
	int a;
	vector<int> v1;
	for(int i=0; i<n; i++){
		cin >> a;
		v1.push_back(a);
	}
	Solution sol;
	vector<string> res;
	res = sol.summaryRanges(v1);
	for(int i=0; i<res.size(); i++){
		cout << res[i] << endl;
	}
	cout << res.size();
	return 0;
}
