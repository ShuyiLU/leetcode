#include<iostream>
#include<vector>
#include<cstring>

using namespace std;

class Solution {
public:
    vector<string> generateAbbreviations(string word) {
        vector<string> res;
        backtrack(word, 0, "", res, 0);
        return res;
    }
    
    void backtrack(const string &word, int index, string tmp, vector<string> &res, int cnt){  //��������indexʱ������index���е�����cnt 
    	if(index == word.length()){
    		if(cnt>0) tmp += to_string(cnt);
    		res.push_back(tmp);
		}
		else{
			backtrack(word, index+1, tmp, res, cnt+1); //�������ִ�������cntͳ�ƣ� 2or, 3r, 4 
			if(cnt>0) backtrack(word, index+1, tmp + to_string(cnt) + word[index], res, 0);  //��ǰͳ��cnt������cnt  2or,abor,ab1r 
			else backtrack(word, index+1, tmp + word[index], res, 0);			
		} 

		
	}
    
};

