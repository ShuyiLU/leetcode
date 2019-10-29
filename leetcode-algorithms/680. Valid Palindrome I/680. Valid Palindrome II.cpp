#include<iostream>
#include<cstring>

using namespace std;

class Solution {
public:
    bool validPalindrome(string s) {
        if(s.length() < 0 ) return false;
        if(s.length() <= 1) return true;
        int i = 0;
        int j = s.length() - 1;
        int count = 0;
        while (i < j){
        	
        	if(s[i] == s[j]){
        		i++;
        		j--;
			}
			else{
				count ++;
				if(count >= 2) break;
				i++;
			}
		}
		
		if(count < 2) return true;
		i = 0;
        j = s.length() - 1;
        count = 0;
		while (i < j){
        	
        	if(s[i] == s[j]){
        		i++;
        		j--;
			}
			else{
				count ++;
				if(count >= 2) break;
				j--;
			}
		}
		
		if(count < 2) return true;
		return false;
		
    }
};

int main(){
	string s;
	cin >> s;
	Solution sol;
	if(sol.validPalindrome(s)) cout << "true" << endl;
	else cout << "false" << endl;
	return 0;
}
