#include<iostream>
#include<cstring>
#include<vector>
#include<set>

using namespace std;

class Solution {
public:
	// s��������ַ���
    // ans���Ϸ��ķ��ظ��Ľ��
    // exp����ǰ�����ĺϷ����ַ���
    // misl�����������Ϸ�������
    // misr�����������Ϸ�������
    // pair��ʣ�»�Ӧ�еġ��������ɶԵ�����
    // i�����������ַ���s��λ��
    vector<string> removeInvalidParentheses(string s) {
        vector<string> res;
        int misl=0, misr=0;
        for(int i=0; i<s.length(); i++){
        	if(s[i] == '(') misl++;
        	else if(s[i] == ')') {
        		if(misl > 0) misl--;
        		else misr++;
			}
		}
		set<string> ans;
		DFS(s, ans, "", misl, misr, 0, 0);
		set<string> :: iterator it;
		for(it = ans.begin(); it!=ans.end(); it++) res.push_back(*it);
		return res;
    }
    
    void DFS(string &s, set<string> &ans, string tmp, int misl, int misr, int pair, int i){ // last record position
    	if(i == s.length()){
    		if(misl == 0 && misr == 0 && pair == 0) {
    			ans.insert(tmp);
			//	return;	
			}
		}
		if(s[i] == '('){
			if(misl > 0) DFS(s, ans, tmp, misl-1, misr, pair, i+1); //s[i]�Ƕ���ģ�ɾ��s[i] 
			DFS(s, ans, tmp + '(', misl, misr, pair+1, i+1);
		}
		else if(s[i] == ')'){
			if(misr > 0) DFS(s, ans, tmp, misl, misr-1, pair, i+1);
			if(pair > 0) DFS(s, ans, tmp+')', misl, misr, pair-1, i+1);
		}
		else DFS(s, ans, tmp+s[i], misl, misr, pair, i+1);
		
	}
};
