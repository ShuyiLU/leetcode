#include<iostream>
#include<stack>
#include<cstring>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        int len = s.length();
        for(int i=0; i<len; i++){
        	if(s[i] == '(' || s[i] == '[' || s[i] == '{'){
        		st.push(s[i]);
			}
			else{
				if(st.empty()) return false;
				else{
					if(s[i] == ']'){
						if(st.top() == '[') st.pop();
						else return false;
					}
					if(s[i] == ')'){
						if(st.top() == '(') st.pop();
						else return false;
					}
					if(s[i] == '}'){
						if(st.top() == '{') st.pop();
						else return false;
					}					
				}
			}
		}
		if(!st.empty()) return false;
		else return true;
    }
};
