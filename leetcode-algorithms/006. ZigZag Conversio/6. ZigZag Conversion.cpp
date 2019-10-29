#include<iostream>
#include<cstring>
#include<vector>

using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows <= 1 || numRows >= s.length()) return s;
        vector<vector<char> > v;
        v.resize(numRows);
        int flag = 0;
        int ii = 0;
        while(ii < s.length()){
        	for(int j=0; j<numRows && ii < s.length(); j++){
        		v[j].push_back(s[ii]);
        		ii++;
			}
			for(int j=numRows-2; j>0 && ii <s.length(); j--){
				v[j].push_back(s[ii]);
				ii++;
			}			 
		}
        string ans;
        ans.resize(s.length());
        int k=0;
        for(int i=0; i<v.size(); i++){
        	for(int j=0; j<v[i].size(); j++){
        		ans[k] = v[i][j];
        		k++;
			}
		}
		return ans;    
    }
};

int main(){
	string s;
	int n;
	cin >> s >> n;
	Solution sol;
	cout << sol.convert(s, n) << endl;
}
