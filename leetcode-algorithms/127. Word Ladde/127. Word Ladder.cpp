#include<iostream>
#include<vector>
#include<cstring>
#include<queue>
#include<set>

using namespace std; 
/*TLE
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int flag = 0;
		for(int i=0; i<wordList.size(); i++){
			if(wordList[i] == endWord){
				flag = 1;
				break;
			}
		}
		for(int i=0; i<wordList.size(); i++){
			if(wordList[i] == beginWord){
				wordList.erase(wordList.begin() + i);
				break;
			}
		}
		if(flag == 0) return 0;
		queue<pair<string, int> >q;
		set<string> s;
		int n = beginWord.size();
		q.push(make_pair(beginWord, 0));
		int res = 0;
		while(!q.empty()){
			string cur_s = q.front().first;
			int cur_l = q.front().second;
		//	cout << cur_s << " " << cur_l << endl;
			
			if(cur_s == endWord){
				res = cur_l+1;
				break;
			}
			
			q.pop();
			for(int i=0; i<n; i++){
				for(int j=0; j<wordList.size(); j++){
				//	if(s.count(wordList[j]) != 0) continue;
					if(cur_s.substr(0, i) == wordList[j].substr(0, i) && cur_s.substr(i+1, n-i-1) == wordList[j].substr(i+1, n-i-1) ){
					
						if(wordList[j] == endWord){
							res = cur_l+2;
							return res;
						}
						
						q.push(make_pair(wordList[j], cur_l+1));
					//	s.insert(wordList[j]);
						wordList.erase(wordList.begin() + j);
						j--;
					}
				}
			}
		}
		return res;
    }
};
*/

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int flag = 0;
		for(int i=0; i<wordList.size(); i++){
			if(wordList[i] == endWord){
				flag = 1;
				break;
			}
		}
		for(int i=0; i<wordList.size(); i++){
			if(wordList[i] == beginWord){
				wordList.erase(wordList.begin() + i);
				break;
			}
		}
		if(flag == 0) return 0;
		queue<pair<string, int> >q;
		set<string> s;
		for(int i=0; i<wordList.size(); i++) s.insert(wordList[i]);
	//	set<string> :: iterator it;
	//	for(it = s.begin(); it!=s.end(); it++) cout << *it << endl; 
		int n = beginWord.size();
		q.push(make_pair(beginWord, 0));
		int res = 0;
		while(!q.empty()){
			string cur_s = q.front().first;
			int cur_l = q.front().second;
			string tmp = cur_s;
			q.pop();
			//cout << cur_s << " " << cur_l << endl;
			
			if(cur_s == endWord){
				res = cur_l+1;
				break;
			}
			
			for(int i=0; i<n; i++){
				for(char ch = 'a'; ch <= 'z'; ch++){
					tmp[i] = ch;
					/*
					if(tmp == endWord){
						res = cur_l + 2;
						break;
					}
					*/
					if(tmp != cur_s && s.count(tmp)>0 ){
						q.push(make_pair(tmp, cur_l+1));
						s.erase(tmp);
					}
					tmp = cur_s;
				}
			}
		}
		return res;
    }
};

int main(){
	string b;
	string e;
	cin >> b >> e;
	int n;
	cin >> n;
	string a;
	vector<string> v;
	for(int i=0; i<n; i++){
		cin >> a;
		v.push_back(a);
		
	}
	Solution sol;
	cout << sol.ladderLength(b, e, v);
}
