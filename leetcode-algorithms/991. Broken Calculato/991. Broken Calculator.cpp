#include<iostream>
#include<vector>

//逆向操作，当 Y > X 时，如果 Y 为偶数，则 Y /= 2，否则 Y + 1，累计答案 1 次。
//如果操作过程中 Y <= X，则终止操作，然后答案累计 X - Y 次。
//证明，当 Y 为偶数时，显然让 X 通过一次加倍操作变成 Y 是最好的；当 Y 为奇数时，最好情况也是让 X 加倍后减去 1。
//如果 Y 在变化中超过了 X，则说明无论如何 X 需要在第一步就减一，否则乘法以后需要更多的代价来减。
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
