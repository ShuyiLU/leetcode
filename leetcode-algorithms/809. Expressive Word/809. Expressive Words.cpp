#include<iostream>
#include<vector>
#include<cstring>

using namespace std;


class Solution {
public:
    int expressiveWords(string S, vector<string>& words) {
        int n = S.length();
        int cnt = 0;
        for(int i=0; i<words.size(); i++)
        {
        	string w = words[i];
			if(w.size() > S.size()) continue;
        	int left = 0 , right = 0;
        	int cnt1, cnt2;
        	while(left < w.size())
        	{
        		
        		if(w[left] != S[right]) break;
        		cnt1 = 1, cnt2=1;
        		while(left+1<w.size() && w[left] == w[left+1]){
        			left++;
        			cnt1++;
				}
				while(right+1<n && S[right] == S[right+1]){
					right++;
					cnt2++;
				}
				left++;
				right++;
				if(cnt1==cnt2 || (cnt1<cnt2 && cnt2>=3)) {
					cout << cnt1 << " " << cnt2 << endl;
					continue;
				}
				else break;
			}
			if(left==w.size()&&right==n && cnt1==cnt2 || (cnt1<cnt2 && cnt2>=3)) cnt++;
		}
		return cnt;
    }
};
/*
class Solution {
public:
    int expressiveWords(string S, vector<string>& words) {
    	int res = 0;
    	for(int i=0; i<words[i].size(); i++){
    		string w = words[i];
    		if(w.size() <= S.size()){
    			int l, r;
				for( l=0, r=0; r<S.size(); r++){
					if(w[l] == S[l]){
						l++;
					}
					else if(r>0 && S[r] == S[r-1] && r+1<S.size()&&S[r]==S[r+1]) r++;//this, last, next
					else if(!(r>1&&S[r]==S[r-1] && S[r]== S[r-2])) break;
				}	
				if(l==w.size() && r==S.size()) res++;
			}
			return res;
		}    	   	
};
    
*/
/*
class Solution {
public:
    int expressiveWords(string S, vector<string>& words) {
        int res = 0;
        for(int i=0; i<words.size(); i++){
        	if(valid(words[i], S)) res++;
		}
		return res;
    }
    
    bool valid(string &w, string &s){
    	if(w.size() > s.size()) return false;
    	int i=0, j=0, n=w.size(), m=s.size();
    	while(i<n){
    		if(w[i] != s[j]) return false;
    		int cnt1=1, cnt2=1;
    		while(i+1<n && w[i] == w[i+1]){
    			i++;
    			cnt1++;
			}
			while(j+1<m && s[j] == s[j+1]){
				j++;
				cnt2++;
			}
			i++;
			j++;
			if(cnt1 == cnt2 || (cnt1<cnt2 && cnt2>=3)) continue;
			else return false;
		}
		return i==n && j==m;
	}
    
    
};
*/

int main(){
	vector<string> v;
	string s;
	string reg;
	cin >> reg;
	int n;
	cin >> n;
	for(int i=0; i<n;i++){
		cin >> s;
		v.push_back(s);
	}
	Solution sol;
	int r = sol.expressiveWords(reg, v);
	cout << r << endl;
}
