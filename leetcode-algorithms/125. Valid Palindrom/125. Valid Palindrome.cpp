#include<iostream>
#include<stack>
#include<cstring>

using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
    	int flag = 0;
    	if(s.length()==0) flag = 0;
    	else{
		
        stack <char> st1;
        stack <char> st2;
        for(int i=0; i<s.length(); i++){
        	if((s[i] >= 'a' && s[i] <= 'z' )||(s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= '0' && s[i] <= '9')){
        		st1.push(s[i]);
			}
			else continue;
		}
		
		for(int i=s.length()-1; i>=0; i--){
        	if((s[i] >= 'a' && s[i] <= 'z' )||(s[i] >= 'A' && s[i] <= 'Z')|| (s[i] >= '0' && s[i] <= '9')){
        		st2.push(s[i]);
			}
			else continue;
		}
		while(!st1.empty()){
			if((st1.top() >= 'a' && st1.top() <= 'z' )||(st1.top() >= 'A' && st1.top() <= 'Z')){
				if(st1.top() == st2.top() || st1.top() == char (st2.top() + 32) ||st1.top() == char (st2.top() - 32) ){
					st1.pop();
					st2.pop();
				}
				else{
					flag = 1;
					//return false;
					break;
				}
			}
			else{
				if(st1.top() == st2.top()){
					st1.pop();
					st2.pop();
				}
				else{
					flag = 1;
					//return false;
					break;
				}
			}
			 
		}
	}
		if(flag == 0 ) return true;
		else return false;
    }
};

int main(){
	string s;
	cin >> s;
	Solution sol;
	if(sol.isPalindrome(s)) cout << "true" << endl;
	else cout << "false" << endl;
}
