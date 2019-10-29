#include<iostream>
#include<cstring>
#include<vector>

using namespace std;

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        int n = digits.length();
        if(n==0) return vector<string> {};
        vector<string> res;
        string tmp;
        tmp.resize(n);
        backtrack(digits, n, 0, res, tmp);
        return res;
    }
    
    void backtrack(string digits, int n, int i, vector<string>& res, string tmp){
    	if(i == n){
    	//	cout << "1" << endl;
    		res.push_back(tmp);
    		return;
		}
    	
    	if(digits[i] >= '2' && digits[i]<'7'){
    	//	cout << "1" << endl;
    		tmp[i] = char( 'a' + (3 * (int (digits[i] - '0') - 2) + 0) ); 
    		backtrack(digits, n, i+1, res, tmp);
    		tmp[i] =  char( 'a' + (3 * (int (digits[i] - '0') - 2) + 1) ); 
    		backtrack(digits, n, i+1, res, tmp);
    		tmp[i] =  char( 'a' + (3 * (int (digits[i] - '0') - 2) + 2) ); 
    		backtrack(digits, n, i+1, res, tmp);
		}
    	
    	else if(digits[i] == '7'){
    	//	cout << "1" << endl;
    		tmp[i] = 'p'; 
    		backtrack(digits, n, i+1, res, tmp);
    		tmp[i] = 'q'; 
    		backtrack(digits, n, i+1, res, tmp);
    		tmp[i] = 'r'; 
    		backtrack(digits, n, i+1, res, tmp);
    		tmp[i] = 's'; 
    		backtrack(digits, n, i+1, res, tmp);
		}
		
		else if(digits[i] == '8'){
		//	cout << "1" << endl;
    		tmp[i] = 't'; 
    		backtrack(digits, n, i+1, res, tmp);
    		tmp[i] = 'u'; 
    		backtrack(digits, n, i+1, res, tmp);
    		tmp[i] = 'v'; 
    		backtrack(digits, n, i+1, res, tmp);
		}
		
		else if(digits[i] == '9'){
    		tmp[i] = 'w'; 
    		backtrack(digits, n, i+1, res, tmp);
    		tmp[i] = 'x'; 
    		backtrack(digits, n, i+1, res, tmp);
    		tmp[i] = 'y'; 
    		backtrack(digits, n, i+1, res, tmp);
    		tmp[i] = 'z'; 
    		backtrack(digits, n, i+1, res, tmp);
		}
    		
	}
    
};

int main(){
	string s;
	cin >> s;
	vector<string> v;
	Solution sol;
	v = sol.letterCombinations(s);
	//cout << v.size() << endl;
	for(int i=0; i<v.size(); i++){
		cout << v[i] << endl;
	}
	return 0;
	
}
