#include<iostream>
#include<cstring>
#include<map>
#include<queue>

using namespace std;

struct c{
	char ch;
	int cnt;
	c() : ch(NULL), cnt(NULL) {}
	c(char t, int x) : ch(t), cnt(x) {}
};

struct cmp{
	bool operator()(c c1, c c2){
		return c1.cnt < c2.cnt;
	}
};


class Solution {
public:
    string reorganizeString(string S) {
        if(S.length() == 0) return "";
        if(S.length() == 1) return S;
        map<char, int> mp;
        for(int i=0; i<S.length(); i++){
        	if(mp.count(S[i]) == 0) mp[S[i]] = 1;
        	else mp[S[i]]++;
		}
		
		priority_queue<c, vector<c>, cmp> p;
		vector<c> v;
		
		map<char, int> :: iterator it;
		for(it = mp.begin(); it!=mp.end(); it++){
			c tmp = new c((*it).first, (*it).second);
			v.push_back(tmp);
		}
		
		for(int i=0; i<v.size();i++) p.push(v[i]);
		
		string res = "";
		res.resize(S.length());
		
		c c1,c2;
		 
		for(int i=0; i<S.length(); i++){
			if(!p.empty()){
				c1 = p.top();
				p.pop();
			}
			
			if(p.empty()) return "";
			
			if(!p.empty()){
				c2 = p.top();
				p.pop();
			}
			
			mp[c1.cnt]--;
			if(mp[c1.cnt] != 0){
				c c11 = new c(c1.ch, c1.cnt);
				p.push(c11);
			} 
			
			
			mp[c2.cnt]--;
			if(mp[c2.cnt] != 0){
				c c22 = new c(c2.ch, c2.cnt);
				p.push(c22);
			} 
			
			res[i] = c1.ch;
			res[i+1] = c2.ch;
			i = i+2;
			
		}
		return res;
    }
};


int main(){
	string s;
	cin >> s;
	Solution sol;
	cout << sol.reorganizeString(s) << endl;
}
