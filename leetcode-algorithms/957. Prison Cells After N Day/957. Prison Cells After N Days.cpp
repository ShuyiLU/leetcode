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
        		if((cells[j-1] & 1) ==( cells[j+1] & 1 )){  //�ж�j-1��j+1�Ƿ���� 
        			if( cells[j] & 1 == 1) cells[j] = 3; //�ж�ԭ���������Ƿ���ȣ� ���Ϊ11 
        			else cells[j] = 2; //����Ϊ10. ����11����10�� ����һλ����1.
					                   //����j-1��j+1���ʱ��Ϊ1. 
				}
			}
			for(int j=0; j<8; j++) cells[j] >>= 1;
		}
		return cells;
    }
};
