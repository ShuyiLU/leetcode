#include<iostream>
#include<vector>
#include<cmath>

using namespace std;
/*
class Solution {
public:
    vector<int> shortestDistanceColor(vector<int>& colors, vector<vector<int> >& queries) {
        vector<int> one;
        vector<int> two;
        vector<int> three;
        int n = queries.size();
        if(n == 0) return vector<int>{};
        vector<int> res(n, 0);
        for(int i=0; i<colors.size(); i++){
        	if(colors[i] == 1) one.push_back(i);
        	else if(colors[i] == 2) two.push_back(i);
        	else three.push_back(i);
		}
		
        for(int i=0; i<n; i++){
        	int target = queries[i][0];
            if(target > colors.size()-1){
                res[i] = -1;
                continue;
            }
        	int pos;
        	if(queries[i][1] == 1) {
        		if(one.size() == 0){
        			res[i] = -1;
        			continue;
				}
        		pos = binerySearch(0, one.size()-1, target, one);
				if(pos > one.size()-1) pos = pos-1;	
        		else if(pos>0 && abs(target - one[pos]) > abs(target-one[pos-1])) pos = pos-1;
        		res[i] = abs(target - one[pos]);
			}
        	else if(queries[i][1] == 2){
        		if(two.size() == 0){
        			res[i] = -1;
        			continue;
				}
        		pos = binerySearch(0, two.size()-1, target, two);
        		
        		if(pos > two.size()-1) pos = pos-1;	
        		else if(pos > 0 && abs(target - two[pos]) > abs(target-two[pos-1])) pos = pos-1;
        		res[i] = abs(target - two[pos]);
			} 
        	else  {
        		if(three.size() == 0){
        			res[i] = -1;
        			continue;
				}
        		pos = binerySearch(0, three.size()-1, target, three);
        		if(pos > three.size()-1) pos = pos-1;	
        		else if(pos > 0 && abs(target - three[pos]) > abs(target-three[pos-1])) pos = pos-1;
        		res[i] = abs(target - three[pos]);
			}
        	
		}
        return res;
        
    }
    
    int binerySearch(int l, int r, int target, const vector<int>& v){
    	
    	while(l <= r){
    		int mid = (l+r)/2;
    		if(v[mid] == target) return mid;
    		else if(v[mid] > target) r= mid-1;
    		else l=mid+1;
		}
    	return l;
		
	}
    
    
}; 
*/


class Solution {
public:
    vector<int> shortestDistanceColor(vector<int>& colors, vector<vector<int> >& queries) {
        int n = colors.size();
        
        if(queries.size() == 0) return vector<int>{};
        vector<int> res(queries.size(), 0);
        
        vector<int> dp1(n, -1);
        vector<int> dp2(n, -1);
        vector<int> dp3(n, -1);
        if(colors[0] == 1) dp1[0] = 0;
        else if(colors[0] == 2) dp2[0] = 0;
        else dp3[0] = 0;
        
        for(int i=1; i<n; i++){
        	if(colors[i] == 1){
        		dp1[i] = i;
			}
			else dp1[i] = dp1[i-1];
			
			if(colors[i] == 2){
        		dp2[i] = i;
			}
			else dp2[i] = dp2[i-1];
			
			if(colors[i] == 3){
        		dp3[i] = i;
			}
			else dp3[i] = dp3[i-1];
		}
		
        
        
		if(colors[n-1] == 1) dp1[n-1] = n-1;
		else if(colors[n-1] == 2) dp2[n-1] = n-1;
		else dp3[n-1] = n-1;
		
		for(int i=n-2; i>=0; i--){
			if(colors[i] == 1){
				dp1[i] = i;
			}
			else{
				if(dp1[i]>0 && dp1[i+1]>0) {
					if(abs(i-dp1[i]) > abs(i-dp1[i+1])) dp1[i] = dp1[i+1];
					else dp1[i] = dp1[i];
				}
				else if(dp1[i+1]>0 && dp1[i]<0) dp1[i] = dp1[i+1];
				else if(dp1[i+1]<0 && dp1[i]>0) dp1[i] = dp1[i];
				else if(dp1[i+1]<0 && dp1[i]<0) dp1[i] = dp1[i];
				
			}
			
			if(colors[i] == 2){
				dp2[i] = i;
			}
			else{
				if(dp2[i]>0 && dp2[i+1]>0) {
					if(abs(i-dp2[i]) > abs(i-dp2[i+1])) dp2[i] = dp2[i+1];
					else dp2[i] = dp2[i];
				}
				else if(dp2[i+1]>0 && dp2[i]<0) dp2[i] = dp2[i+1];
				else if(dp2[i+1]<0 && dp2[i]>0) dp2[i] = dp2[i];
				else if(dp2[i+1]<0 && dp2[i]<0) dp2[i] = dp2[i];
			}
			
			if(colors[i] == 3){
				dp3[i] = i;
			}
			else{
				if(dp3[i]>0 && dp3[i+1]>0) {
					if(abs(i-dp3[i]) > abs(i-dp3[i+1])) dp3[i] = dp3[i+1];
					else dp3[i] = dp3[i];
				}
				else if(dp3[i+1]>0 && dp3[i]<0) dp3[i] = dp3[i+1];
				else if(dp3[i+1]<0 && dp3[i]>0) dp3[i] = dp3[i];
				else if(dp3[i+1]<0 && dp3[i]<0) dp3[i] = dp3[i];
			}
			
		}
        
        for(int i=0; i<n; i++){
            cout << i << ": " << dp1[i] << " " << dp2[i] << " " << dp3[i] << endl;
        }
		
		for(int i=0; i<queries.size(); i++){
			int index = queries[i][0];
			int target = queries[i][1];
            if(index >= n) {
                res[i] = -1;
                continue;
            }
			if(target == 1) res[i] = dp1[index]<0? -1 : abs(index-dp1[index]);
			else if(target == 2) res[i] = dp2[index]<0? -1 : abs(index-dp2[index]);
			else res[i] = dp3[index]<0? -1 : abs(index-dp3[index]);
		}
		return res;
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
	vector<vector<int> > k(1, vector<int>{});
	k[0].push_back(3);
	k[0].push_back(3);
	Solution sol;
	vector<int> ans = sol.shortestDistanceColor(v, k);
}
