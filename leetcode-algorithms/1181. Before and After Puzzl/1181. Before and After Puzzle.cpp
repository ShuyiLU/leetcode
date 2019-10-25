#include<iostream>
#include<cstring>
#include<vector>
#include<set>
#include<map> 

using namespace std;

class Solution {
public:
    vector<string> beforeAndAfterPuzzles(vector<string>& phrases) {
        map<string, vector<int> > mp;
        set<string> tmp;
        vector<string> res;
        for(int i=0; i<phrases.size(); i++){
        	string s = phrases[i];
        	for(int j=0; j<s.length(); j++){
        		if(j == s.length()-1){
        			mp[s].push_back(i);
        			break;
				}
        		if(s[j] == ' ' ){
        			string pre = s.substr(0, j);
        			mp[pre].push_back(i);
        			break;
				}	
			}
		}
		map<string, vector<int> > :: iterator it2;
		for(it2 = mp.begin(); it2 != mp.end(); it2++){
			cout << (*it2).first << " ";
			for(int i=0; i<(*it2).second.size(); i++){
				cout << (*it2).second[i] << " ";
			}
			cout << endl;
		}
		
		for(int i=0; i<phrases.size(); i++){
			string s = phrases[i];
			for(int j=s.length()-1; j>=0; j--){
				if(j == 0) {
					string tail = s;
					if(mp.count(tail) > 0){
						for(int k=0; k<mp[tail].size(); k++){
							if( i == mp[tail][k]) continue;
							string t = phrases[mp[tail][k]];
							tmp.insert(t);
						}
					}
                    break;
				}
                   
				
				if(s[j] == ' '){
					string tail = s.substr(j+1, s.length()-j-1);
					if(mp.count(tail) > 0){
						for(int k=0; k<mp[tail].size(); k++){
							if( i == mp[tail][k]) continue;
							string t = s.substr(0, j+1) + phrases[mp[tail][k]];
							tmp.insert(t);
						}
					}
                    break;
				}
			}
		}
		set<string> :: iterator it;
		for(it = tmp.begin(); it!= tmp.end(); it++){
			res.push_back(*it);
		}
		
        return res;
        
    }
};


int main(){
	vector<string> v;
	int n;
	cin >> n;
	string st;
	for(int i=0; i<n; i++){
		cin >> st;
		v.push_back(st);
	}
	Solution sol;
	vector<string> res = sol.beforeAndAfterPuzzles(v);
	for(int i=0; i<res.size(); i++) cout << v[i] << endl;
}
