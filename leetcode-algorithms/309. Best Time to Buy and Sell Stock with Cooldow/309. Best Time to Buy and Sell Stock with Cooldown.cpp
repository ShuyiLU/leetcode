#include<iostream>
#include<vector>

using namespace std;

/*����״̬��
��i��cooldown�� cooldown[i] =  sell[i-1]
��i��sell��sell[i] =  max(buy[i-1]+p[i], sell[i-1]) : i-1�����룬 i������ �� i-1��ǰ��ӵ�й�Ʊ�� i-1Ҳ��������
��i��buy �� buy[i] = max(cooldown[i-1]-p[i], buy[i-1]) : i-1�����䶳�ڣ� �� i-1��ǰ�Ϳ������Ʊ 
*/
class Solution {
public:
    int maxProfit(vector<int>& p) {
        int n = p.size();
		if( n == 0 ) return 0;
		vector<int> cooldown(n, 0);
		vector<int> sell(n, 0);
		vector<int> buy(n,0);
		
		sell[0] = 0;
		buy[0] = -p[0];
		
		for(int i=1; i<n; i++){
			cooldown[i] = sell[i-1];
			sell[i] = max(buy[i-1]+p[i], sell[i-1]);
			buy[i] = max(cooldown[i-1]-p[i], buy[i-1]);
		}
		
		return max(max(cooldown[n-1], sell[n-1]), buy[n-1]);
		
    }
};
