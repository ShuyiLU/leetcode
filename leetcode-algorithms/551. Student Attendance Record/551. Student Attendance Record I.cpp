class Solution {
public:
    bool checkRecord(string s) {
    	if(s.length() <= 1) return true;
        int cnt1=0, cnt2=0;
        for(int i=0; i<s.length(); i++){
        	if(i == 0){
        		if(s[i] == 'A') cnt1 = 1;
        		else if(s[i] == 'L')cnt2 = 1;
			}
			else{
				if(s[i] == 'A') cnt1++;
				else if(s[i] == 'L'){
					if(s[i-1] == 'L') cnt2++;
					else cnt2 = 1;
				}
				if(cnt1 > 1 || cnt2 > 2 ) return false;
			}
		}
		return true;
    }
};
