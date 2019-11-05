
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
			maxn = *max_element(tmp.begin(), tmp.end());//最大次数
			while(j-i+1 - maxn > k){  //区间长度 - 区间内出现最多次数的字母 = 使该区间所有字母一样的最少改变次数
				
				tmp[s[i]-'A']--;
                i++;    
				maxn = *max_element(tmp.begin(), tmp.end());
			}
			res = max(res, j-i+1);
		} 
		return res;
    }
};

