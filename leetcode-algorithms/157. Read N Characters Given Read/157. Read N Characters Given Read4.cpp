#include<iostream>
#include<cstring>

int read4(char *buf);

class Solution {
public:
    /**
     * @param buf Destination buffer
     * @param n   Maximum number of characters to read
     * @return    The number of characters read
     */
    int read(char *buf, int n) {
    	if(n == 0) return 0;
		int res = 0;
		for(;;){
			//buf = buf + 4;
			if(res + read4(buf) <n){
				res = res + read4(buf);
				if(read4(buf) < 4) break;
			}
			else{
				buf[n-res] = 0;
				res = n;
				break;
			}
			buf = buf + 4;
		}
		return res;
    }
};

