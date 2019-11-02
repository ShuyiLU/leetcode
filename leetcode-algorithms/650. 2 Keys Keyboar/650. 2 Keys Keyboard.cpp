class Solution {
public:
    int minSteps(int n) {
        if(n <= 1) return 0;
		return dp(n, 1, 1) + 1;
    }
	
	int dp(int n, int have, int c){  //have: ��ǰ����have��A�� c:��ǰ��������c��A
		if(n == have) return 0;
		else if(n< have) return 1001;
		else if((n-have) % c != 0) return 1001;
		int tmp1 = 2 + dp(n, have*2, have);//���Ƶ�ǰȫ���� c��have����������have��
		int tmp2 = 1 + dp(n, have+c, c);//ֻpaste1һ�Σ� ����c���� copy����Ȼ��c��
		return min(tmp1, tmp2);
	}
	
	
};
