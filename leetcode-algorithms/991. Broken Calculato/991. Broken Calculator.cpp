#include<iostream>
#include<vector>

//����������� Y > X ʱ����� Y Ϊż������ Y /= 2������ Y + 1���ۼƴ� 1 �Ρ�
//������������� Y <= X������ֹ������Ȼ����ۼ� X - Y �Ρ�
//֤������ Y Ϊż��ʱ����Ȼ�� X ͨ��һ�μӱ�������� Y ����õģ��� Y Ϊ����ʱ��������Ҳ���� X �ӱ����ȥ 1��
//��� Y �ڱ仯�г����� X����˵��������� X ��Ҫ�ڵ�һ���ͼ�һ������˷��Ժ���Ҫ����Ĵ���������
using namespace std;

class Solution {
public:
    int brokenCalc(int X, int Y) {
        int res = 0;
        if(X == Y) return 0;
        while(X < Y){
        	if(Y%2 == 0) Y = Y/2;
        	else Y = Y +1;
        	res += 1;
		}
		res += (X-Y);
		return res;
    }
    
    
};
