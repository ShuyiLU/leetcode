#include<iostream>
#include<stack>;
#include<cstring>

using namespace std;

class Solution {
public:
    bool backspaceCompare(string S, string T) {
        stack<char> s1, s2;
        string st1, st2;
        st1 = "";
        st2 = "";
        while(!s1.empty()) s1.pop();
		while(!s2.empty()) s2.pop();
		for(int i=0; i<S.length(); i++){
			if(S[i] != '#') s1.push(char(S[i]));
			else{
				if(!s1.empty()) s1.pop();
				else continue;
			}
		}
		if(s1.empty()) st1 = "";
		else{
			while(!s1.empty()){
				st1 = st1 + s1.top();
				s1.pop();
			}
		}
		for(int i=0; i<T.length(); i++){
			if(T[i] != '#') s2.push(char(T[i]));
			else{
				if(!s2.empty()) s2.pop();
				else continue;
			}
		}
		if(s2.empty()) st2 = "";
		else{
			while(!s2.empty()){
				st2 = st2 + s2.top();
				s2.pop();
			}
		}
		//cout  <<  st1  <<  " "  << st2 << endl;
		if(st1 == st2) return true;
		else return false;
    }
};

int main(){
	string s1, s2;
	cin >> s1 >> s2;
	Solution sol;
	if(sol.backspaceCompare(s1,s2)) cout << "true" << endl;
	else cout << "false" << endl;
	return 0;
}
