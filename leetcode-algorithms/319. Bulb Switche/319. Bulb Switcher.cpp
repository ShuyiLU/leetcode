class Solution {
public:
    int bulbSwitch(int n) {
		int i=1;
		int cnt=0;
		while(i*i <= n){
			cnt++;
			i++;
		}
		
		return cnt;
    }
};