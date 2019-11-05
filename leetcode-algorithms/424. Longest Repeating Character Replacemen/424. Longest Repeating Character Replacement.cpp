
class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> tmp(26, 0);
		int maxn = 0;
		int i=0;
		int res = 0;
		for(int j=0; j<s.length(); j++){
			tmp[s[j] - 'A']++;
			//maxn = max(maxn, tmp[s[j] - 'A']); 
			maxn = *max_element(tmp.begin(), tmp.end());//������
			while(j-i+1 - maxn > k){  //���䳤�� - �����ڳ�������������ĸ = ʹ������������ĸһ�������ٸı����
				
				tmp[s[i]-'A']--;
                i++;    
				maxn = *max_element(tmp.begin(), tmp.end());
			}
			res = max(res, j-i+1);
		} 
		return res;
    }
};

