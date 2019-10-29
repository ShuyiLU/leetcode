#include<iostream>
#include<cstring>
#include<string>

using namespace std;

/*
class Solution {
public:
    string reverseWords(string s) {
    	if(s == "") return "";
        int len = s.length();
        //cout << len << endl;
        //for(int i=0; i<len; i++) cout <<s[i];
        //cout << endl;
        string ans;
        ans.resize(len);
        for(int i=0; i<len; i++) ans[i]=' ';
        int a=0, b=0, k=len-1;
        while(b<len && a<len){
        	if(s[a] == ' ') a++;
        	else{
        		b = a;
        		while(s[b+1] != ' ' && b+1<len) b++;
        		int tem = b-a;
        		if(tem == 0) ans[k] = s[a];
        	 
        		else{
        			//cout << a  << " " <<  b <<endl;
        			int j = k - tem;
        			for(; a<=b; a++){
        			    ans[j] = s[a];
        			    j++;
        			    //cout << a << " ";
					}
				}
        		
				k = k - tem - 2;
				a++;
        		
			}
			//a++;
		}
        
  		int pos = 0;
  		for(pos=0; pos<len; pos++){
  			if(ans[pos] == ' ') continue;
  			else break;
		  }
		  string ans2;

		  ans2 = ans.substr(pos, len-pos);
		  // cout << ans2.length() << endl;
        return ans2;
        
    }
};
*/
 //O(1) Space;
class Solution {
public:
    string reverseWords(string s) {
        if(s == "") return "";
        int len = s.length();
        for(int i=0; i<len/2; i++){
        	swap(s[i],s[len-i-1]);
		}
		
		int l=0, r=0;
		int flag = 0;;
		while(l<len && r<len){
			if(s[l] == ' ') {
				l++;
			//	flag++
			}
			else{
				if(flag == 0) flag = 1;
				
				else{				
					if(l-r > 2){
						int t = l - (r+2);
						for(int k=l; k<len; k++) {
							s[k-t] = s[k];
						}
						s.resize(len-t);
					//	cout << s.length() << endl;
						for(int i=0; i<s.length(); i++) cout << s[i];
						cout << endl;
						l = r+2;
					//	cout << l << endl;
					}
				}
				
				r = l;
				while(s[r+1] != ' ' && r < len) r++;
				int tem = r-l;
				if(tem == 0) l++;
				else{
					for(int j=l; j<=l+tem/2; j++) swap(s[j], s[l+r-j]);
					l = r+1;
				}				
			}
		}
		cout << s.length()  << endl;
		return s;
    }
};


int main(){
	string s;
	getline(cin, s);
	Solution sol;
//	sol.reverseWords(s);
	cout << sol.reverseWords(s) << endl;
}
