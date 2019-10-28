class Solution {
public:
    int divide(int dividend, int divisor) {
    	int ans=0;
        if (dividend==-2147483648&&divisor==-1) return 2147483647;
       	long long a=dividend, b=divisor;
        int sgn=1;
        if (a>0&&b<0) {
            b=-b; sgn=-1;
        }
        if (a<0&&b>0) {
            a=-a; sgn=-1;
        }
        if (a<0&&b<0) {
        	b=-b; a=-a;
        }
        
        while (a>=b) {
        	int i=0;
            for (; ; i++) {
                if ((b<<(i+1))>a) break;
            }
             a-=(b<<i); ans+=(1<<i);
        }
        return sgn*ans;
    }
};
