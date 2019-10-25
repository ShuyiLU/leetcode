#include<iostream>
#include<cstring>

using namespace std;

class Solution {
public:
    string nextClosestTime(string time) {
    	int a = time[0] - '0';
    	int b = time[1] - '0';
    	int c = time[3] - '0';
    	int d = time[4] - '0';
        string output;
        output.resize(5);
        int s[4];
        s[0] = a;
        s[1] = b;
        s[2] = c;
        s[3] = d;
        int k = 1440;
        int flag;
        while(k >= 0){
        	flag = 0;
        	k--;
        	s[3] = s[3] + 1;
        	if(s[3] > 9){
        		s[3] = 0;
        		s[2] = s[2] + 1;
			}
        	if(s[3] + s[2]*10 > 59) {
        		s[3] = 0;
        		s[2] = 0;
        		s[1] = s[1] + 1;
        		if(s[1] > 9) {
        			s[1] = 0;
        			s[0] = s[0] + 1;
				}
				if(s[0]*10+s[1] > 23){
					s[1] = 0;
					s[0] = 0;
				}
			}
        	if(s[0]!=a && s[0]!= b && s[0]!=c && s[0]!=d) {
        		flag = 1;
        		continue;
			}
        	if(s[1]!=a && s[1]!= b && s[1]!=c && s[1]!=d) {
        		flag = 1;
        		continue;
			}
			if(s[2]!=a && s[2]!= b && s[2]!=c && s[2]!=d) {
        		flag = 1;
        		continue;
			}
			if(s[3]!=a && s[3]!= b && s[3]!=c && s[3]!=d) {
        		flag = 1;
        		continue;
			}
			if(flag == 0) {
				output[0] = s[0] + '0';
				output[1] = s[1] + '0';
				output[2] = ':';
				output[3] = s[2] + '0';
				output[4] = s[3] + '0';
				return output;
			}
		}
    }
};

int main(){
	string s;
	cin >> s;
	Solution sol;
	cout << sol.nextClosestTime(s) << endl;
	return 0;
}
