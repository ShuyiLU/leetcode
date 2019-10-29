#include<iostream>
#include<vector>
#include<set>
#include<map>
#include<string>

using namespace std;

class Solution {	
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        int len = paragraph.length();
        int i=0;
        string st="";
        map<string, int> mp;
        set<string> s;
        if(!banned.empty()){
            for(int j=0; j<banned.size(); j++){
				s.insert(banned[j]);
			}
		}
		if(banned.empty()){
			while(!s.empty()) s.clear();
		}
        while(i<len){
        	if( paragraph[i]>=65 && paragraph[i]<=90 ){
        		st = st + char(paragraph[i] + 32 );
        		i++;
			}
			else if(paragraph[i] >=97 && paragraph[i] <=122){
				st = st + paragraph[i];
				i++;
			}
			else{
				if(st != ""){
				if(banned.empty() || s.count(st) == 0){
					if(mp.count(st) > 0) mp[st] = mp[st] + 1;
					else mp[st] = 1;
					st = "";
					i++;
				}
				if(s.count(st)>0) {
					st = "";
					i++;
					continue;
				}	
				}
				else{
					i++;
				}
				
				
			}
		}
		if(st != ""){
			if(banned.empty() || s.count(st) == 0){
					if(mp.count(st) > 0) mp[st] = mp[st] + 1;
					else mp[st] = 1;
					st = "";
				}
				if(s.count(st)>0) {
					st = "";
				}
		}
		//cout << st << endl;
		map<string, int> :: iterator it;
		string max_f = "";
		int max_s = 0;
		for(it=mp.begin(); it!=mp.end(); it++){
		//	cout << it->first << " " << it->second << endl;
			if(it->second > max_s){
				max_s = it->second;
				max_f = it->first;
			}
		}
		return max_f;
    }
};

int main(){
	string p = "Bob hit a ball, the hit BALL flew far after it was hit.";
	//cin >> p;
	string b = "hit";
//	string a = "bob";
	//cin >> b;
	vector<string> v;
	v.push_back(b);
//	v.push_back(a);
	Solution sol;
	string st = sol.mostCommonWord(p,v);
	cout << st << endl;
	return 0;
}
