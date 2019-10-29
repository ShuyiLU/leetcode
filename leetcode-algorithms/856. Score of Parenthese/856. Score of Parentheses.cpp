#include<iostream>
#include<cstring>
#include<stack>
#include<vector>

using namespace std;

class Solution {
public:
    int scoreOfParentheses(string S) {
        stack<int> st;
        for(int i=0; i<S.length(); i++){
        	if(S[i] == '(') st.push(-1);
        	else{
        		int c = st.top();
        		if(c == -1){
        			st.pop();
        			st.push(1);
				}
				else{
					int num = 0;
					while(st.top() != -1){
						num += st.top();
						st.pop();
					}
					st.pop();
					st.push(num*2);
					
				}
			}
		}
        int ans = 0;
        while(!st.empty()){
            ans += st.top();
            st.pop();
        }
		return ans;
    }
};
