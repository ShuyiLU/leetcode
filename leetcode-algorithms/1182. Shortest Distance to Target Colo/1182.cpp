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
				if(dp1[i]>=0 && dp1[i+1]>=0) {
					if(abs(i-dp1[i]) > abs(i-dp1[i+1])) dp1[i] = dp1[i+1];
				}
				else if(dp1[i+1]>=0) dp1[i] = dp1[i+1];
				
			}
			
			if(colors[i] == 2){
				dp2[i] = i;
			}
			else{
				if(dp2[i]>=0 && dp2[i+1]>=0) {
					if(abs(i-dp2[i]) > abs(i-dp2[i+1])) dp2[i] = dp2[i+1];
				}
				else if(dp2[i+1]>=0) dp2[i] = dp2[i+1];
			}
			
			if(colors[i] == 3){
				dp3[i] = i;
			}
			else{
				if(dp3[i]>=0 && dp3[i+1]>=0) {
					if(abs(i-dp3[i]) > abs(i-dp3[i+1])) dp3[i] = dp3[i+1];
				}
				else if(dp3[i+1]>=0) dp3[i] = dp3[i+1];
			}
			
		}
        /*
        for(int i=0; i<n; i++){
            cout << i << ": " << dp1[i] << " " << dp2[i] << " " << dp3[i] << endl;
        }
		*/
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