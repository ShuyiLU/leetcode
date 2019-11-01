class Solution {
public:
    string smallestSubsequence(string text) {
        string res = "";
        vector<int> cnt(26);
        vector<int> used(26);
        for(int i=0; i<text.length(); i++){
        	char ch = text[i];
        	cnt[ch-'a']++; 
		}
		for(int i=0; i<text.length(); i++){
			char ch = text[i];
			cnt[ch-'a']--; //可知后面还剩多少个相同的ch 
			if(used[ch-'a'] != 0) continue; //当前ch使用过 
			while(!res.empty() && ch < res.back() && cnt[res.back() - 'a'] != 0){ //始终比较当前res的末尾为当前的ch大小
																				 // 循环中保证res不为空而且末位的个数不会小于1 
				used[res.back()-'a'] --;
				res.pop_back();
			} 
			res.push_back(ch);
			used[ch-'a']++;
		} 
		return res;
    }
};
