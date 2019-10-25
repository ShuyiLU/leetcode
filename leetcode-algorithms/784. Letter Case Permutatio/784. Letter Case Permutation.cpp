#include<iostream>
#include<cstring>
#include<vector>
#include<string>
#include<ctype.h>

using namespace std;

class Solution {
private:
 //vector<string> res;
public:
    vector<string> letterCasePermutation(string S) {
        vector<string> res;
        int n = S.length();
        if(n==0) return vector<string>{};
        string tmp;
        tmp.resize(n);
        backtrack(S,n,0,tmp, res);
        return res;
    }
    
    void backtrack(string S, int n, int count, string tmp, vector<string>& res){
    	if(count == n){
    		//cout << "1" << endl;
    		//cout << tmp << endl;
    		res.push_back(tmp);
    		return;
		}
		
		//if(count > n) return;
		
		if(S[count] >= '0' && S[count] <= '9') {
			//cout << "2" << endl;
			tmp[count] = S[count];
			backtrack(S,n,count+1, tmp, res);
		}
		
		else{
			//cout << "3" << endl;
			tmp[count] = tolower(S[count]);
			backtrack(S,n, count+1, tmp, res);
			tmp[count] = toupper(S[count]);
			backtrack(S,n, count+1, tmp, res);
		}	
	}
   
};

int main(){
	string s;
	cin >> s;
	vector<string> v;
	Solution sol;
	v = sol.letterCasePermutation(s);
	//cout << v.size() << endl;
	for(int i=0; i<v.size(); i++){
		cout << v[i] << endl;
	}
	return 0;
	
}
