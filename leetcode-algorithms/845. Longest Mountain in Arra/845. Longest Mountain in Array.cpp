class Solution {
public:
    int longestMountain(vector<int>& A) {
        vector<int> dp_order(A.size(), 0);
		vector<int> dp_reverse(A.size(), 0);
		
		for(int i=1; i<A.size(); i++){
			if(A[i] > A[i-1]) dp_order[i] = dp_order[i-1]+1;
            //cout << dp_order[i] << " " ;
		}
		
		for(int i=A.size()-1; i>0; i--){
			if(A[i-1] > A[i]) dp_reverse[i-1] = dp_reverse[i]+1;
            //cout << dp_reverse[i] << " " ;
		}
		
		int res = 0;
		
		
		for(int p=0; p<A.size(); p++){
            if(dp_order[p] != 0 && dp_reverse[p] != 0){  //Á½±ßÏàµÈ
               res = max(res, dp_order[p]+dp_reverse[p]+1);  
            }
			
		}
		return res;
    }
};
