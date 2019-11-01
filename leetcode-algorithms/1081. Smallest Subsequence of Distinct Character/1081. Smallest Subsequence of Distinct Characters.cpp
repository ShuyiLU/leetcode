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
			cnt[ch-'a']--; //��֪���滹ʣ���ٸ���ͬ��ch 
			if(used[ch-'a'] != 0) continue; //��ǰchʹ�ù� 
			while(!res.empty() && ch < res.back() && cnt[res.back() - 'a'] != 0){ //ʼ�ձȽϵ�ǰres��ĩβΪ��ǰ��ch��С
																				 // ѭ���б�֤res��Ϊ�ն���ĩλ�ĸ�������С��1 
				used[res.back()-'a'] --;
				res.pop_back();
			} 
			res.push_back(ch);
			used[ch-'a']++;
		} 
		return res;
    }
};
