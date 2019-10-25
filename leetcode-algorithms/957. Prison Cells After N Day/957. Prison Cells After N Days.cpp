#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    vector<int> prisonAfterNDays(vector<int>& cells, int N) {
        N = N%14;
        if(N==0) N = 14;
        for(int i=0; i<N; i++){
        	for( int j=1; j<7; j++){
        		if((cells[j-1] & 1) ==( cells[j+1] & 1 )){  //判断j-1和j+1是否相等 
        			if( cells[j] & 1 == 1) cells[j] = 3; //判断原来与现在是否相等， 相等为11 
        			else cells[j] = 2; //不等为10. 不管11还是10， 右移一位后还是1.
					                   //满足j-1和j+1相等时即为1. 
				}
			}
			for(int j=0; j<8; j++) cells[j] >>= 1;
		}
		return cells;
    }
};
