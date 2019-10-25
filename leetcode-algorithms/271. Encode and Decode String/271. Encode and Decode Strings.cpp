#include<iostream>
#include<vector>
#include<cstring>

//长度+特殊分隔符识别唯一字符串； 
class Codec {
public:

    // Encodes a list of strings to a single string.
    string encode(vector<string>& strs) {
        string s = "";
		for(int i=0; i<strs.size(); i++) {
			s += to_string(strs[i].length()) + "&" + strs[i];
		}
		return s;
    }

    // Decodes a single string to a list of strings.
    vector<string> decode(string s) {
        int len = s.length();
        vector<string> strs;
        string s_len = "";
        int i = 0;
        while(i<len){
        	if(s[i] != '&'){
        		s_len += s[i];
        		i++;
			} 
        	else{
        		int str_len = atoi(s_len.c_str());
        		string str = "";
				str = s.substr(i+1, str_len);
        		strs.push_back(str);
        		s_len = "";
        		i = i + str_len + 1;
        		
			}
		}
		return strs;
    }
};
