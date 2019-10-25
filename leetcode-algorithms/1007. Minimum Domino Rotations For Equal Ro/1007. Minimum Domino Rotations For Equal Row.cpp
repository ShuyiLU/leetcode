#include<iostream>
#include<vector>

class Solution {
public:
    int minDominoRotations(vector<int>& A, vector<int>& B) {
        int res = INT_MAX;
        for(int i=1; i<=6; i++){
        	int tmpA = 0, tmpB = 0;
        	bool flag = 1;
        	for(int j=0; j<A.size(); j++){
        		if((A[j] != i && B[j] != i) || tmpA>=res || tmpB >= res){
        			flag = 0;
        			break;
				}
				if(A[j] != i && B[j] == i) tmpA++;
				if(B[j] != i && A[j] == i) tmpB++;
			} 
			if(flag) res = min(res, min(tmpA, tmpB));
		}
        if(res == INT_MAX) return -1;
        return res;
    }
};
