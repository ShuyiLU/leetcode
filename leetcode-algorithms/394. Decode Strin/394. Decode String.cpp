#include<iostream>
#include<cstring>
#include<stack> 
#include <sstream>
#include<algorithm>

using namespace std;
/*
class Solution {
public:
    string decodeString(string s) {
        if(s.length() == 0) return "";
        stack<char> st;
        int i=0;
      // for(int i=0; i<s.length(); i++){
      //  	if(st)
	  //	}
	    string nums="";
	    string str="";
	    string ans="";
	    string temp="";
	  	while(i<s.length()){
	  		if(s[i] == ']'){
	  			temp="";
	  			while(!st.empty() && st.top() != '[' ){
	  				str += st.top();
	  				st.pop();
				  }
				  reverse(str.begin(), str.end());
				  if(st.top() == '[')st.pop();
				  while(!st.empty() && st.top() >= '0' && st.top() <= '9'){
				  	nums += st.top();
				  	st.pop();
				  }
				  if(st.top() == '[')st.pop();
				  reverse(nums.begin(), nums.end());
				  int n = atoi(nums.c_str());
				  
				  while(n>0){
				  	temp += str;
				  	n--;
				  }
				  str = temp;
				  if(st.empty()) {
				  	ans += str;
				  	str = "";
				  }
				  nums="";
			  }
			    else{
		  			st.push(s[i]);
		  		}
		  		i++;
		  }
		  //temp ="";
		  str ="";
		  while(!st.empty()){
		  	str += st.top();
		  	st.pop();
		  }
		  if(str != ""){
		  	reverse(str.begin(), str.end());
		  	ans += str;
		  } 
		 return ans;
    }
};
*/
/*
class Solution {
public:
    string decodeString(string s) {
    	if(s.length() == 0) return "";
    	stack<char> st;
    	int i=0;
    	string nums = "";
    	string alp = "";
    	string ans = "";
    	string temp = "";
    	int n=0;
    	while(i<s.length()){
    		if(s[i] == ']' && !st.empty()){
    			temp = "";
    			while(!st.empty() && st.top() != '['){
    				if(st.top() <= 'z' && st.top() >= 'a') alp += st.top();
    				if(st.top() <= '9' && st.top() >= '0') nums += st.top();
    				st.pop();
				}
				if(!st.empty()) st.pop();
    			reverse(alp.begin(), alp.end());
    			reverse(nums.begin(), nums.end());
    			n = atoi(nums.c_str());
    			while(n>0) {
    				temp += alp;
    				n--;
				}
				alp = temp;
			}
			else{
				st.push(s[i]);
			}
			
			i++;
			if(st.empty()){
				ans += alp;
				alp = "";
				nums = "";
			}
			
		
		}
    	alp = "";
    	while(!st.empty()){
		  	alp += st.top();
		  	st.pop();
		  }
		  if(alp != ""){
		  	reverse(alp.begin(), alp.end());
		  	ans += alp;
		  } 
		 return ans;
    }
};
*/

class Solution {
private:
	int k = 0;	
	
public:
    string decodeString(string s) {
    	if(s.length() == 0) return "";
        return DFS(s);
    }
    
    
    string DFS(string s){
    	string ans;
    	int num = 0;
    	while(k < s.length()){
    		if(s[k] <= '9' && s[k] >= '0') {
    			num = num * 10 + int (s[k] - '0');
				k++;	
			}			
			else if(s[k] == '['){
				k++;
				string tem = DFS(s);
				while(num>0){
					ans += tem;
					num--;
				}
				num = 0;
			}			
			else if(s[k] == ']'){
				k++;
				return ans;
			}
			
			else{
				ans += s[k];
				k++;
			}			
			
		}
		return ans;
	} 
    
    
};






int main(){
	string s;
	cin >> s;
	Solution sol;
	cout << sol.decodeString(s) << endl;
}
