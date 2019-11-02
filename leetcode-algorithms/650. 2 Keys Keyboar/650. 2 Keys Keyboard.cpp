class Solution {
public:
    int minSteps(int n) {
        if(n <= 1) return 0;
		return dp(n, 1, 1) + 1;
    }
	
	int dp(int n, int have, int c){  //have: 当前已有have个A， c:当前复制里是c个A
		if(n == have) return 0;
		else if(n< have) return 1001;
		else if((n-have) % c != 0) return 1001;
		int tmp1 = 2 + dp(n, have*2, have);//复制当前全部， c有have个，新增了have个
		int tmp2 = 1 + dp(n, have+c, c);//只paste1一次， 增加c个， copy里依然是c个
		return min(tmp1, tmp2);
	}
	
	
};
