#include<iostream>
#include<cstring>

using namespace std;

class Solution {
public:
    string parseTernary(string expression) {
    	if(expression.find('?') == string::npos) return expression;
    	string s1;
        if(expression[0] == 'T'){
        	int d = find_divide(expression.substr(2, expression.length()-2));
        	return parseTernary(expression.substr(2, d));
		}
		else{
			int d = find_divide(expression.substr(2, expression.length()-2));
			return parseTernary(expression.substr(d+3, expression.length()-d-3));
		}
		
    }
    
    //string parse(string s, int i)
    int find_divide(string s){
    	int flag = 0;
    	for(int i=0; i<s.length(); i++){
    		if(s[i] == '?') flag++;
    		else if(s[i] == ':') flag--;
    		if(flag<0) return i; //i for ? 
		}
		return s.length();
	}
    
};



class Solution {
public:
    string parseTernary(string expression) {
        stack<char> s;
        for(int i=expression.length()-1; i>=0; i--){
        	if(expression[i] != '?') s.push(expression[i]);
        	if(expression[i] == '?'){
        		char first = s.top();
        		s.pop();
        		s.pop();
        		char second = s.top();
        		s.pop();
        		if(expression[i-1] == 'T'){
        			s.push(first);
				}
				else s.push(second);
			}	
		}
		return string(1, s.top());
    }
};
