#include<iostream>
#include<cstring>
#include<set>
#include<map>

using namespace std; 
/*
class Solution {
public:
    bool isIsomorphic(string s, string t) {
    	int flag = 0;
        for(int i=0; i<s.length(); i++){
        	for(int j=i; j<s.length(); j++){
        		if(s[i] == s[j]){
        			if(t[i] != t[j]) return false;
				}
				else{
					if(t[i] == t[j]) return false;
				}
			}
		}
		return true;
    }
};
*/

class Solution {
public:
    bool isIsomorphic(string s, string t) {
    	set<char> ss;
    	set<char> st;
    	map<char, int> s_map;
    	map<char, int> t_map;
    	map<char, int> :: iterator it1;
    	map<char, int> :: iterator it2;
    	int k = 0;
    	for(int i=0; i<s.length(); i++){
    		if(ss.count(s[i]) == 0){
    			k++;
    			ss.insert(s[i]);
    			s_map.insert(make_pair(s[i],k));
			}
			else{
				continue;
			}
		}
		k=0;
		/*
		for(map<char,int> :: iterator it = s_map.begin(); it!=s_map.end(); it++){
			cout << "s_map: " << (*it).first << " " << (*it).second << endl;
		}
		*/
		for(int i=0; i<t.length(); i++){
    		if(st.count(t[i]) == 0){
    			k++;
    			st.insert(t[i]);
    			t_map.insert(make_pair(t[i],k));
			}
			else{
				continue;
			}
		}
		/*
		for(map<char,int> :: iterator it = t_map.begin(); it!=t_map.end(); it++){
			cout << "t_map: " << (*it).first << " " << (*it).second << endl;
		}
		*/
		for(int i=0; i<s.length(); i++){
			it1 = s_map.find(s[i]);
			it2 = t_map.find(t[i]);
			if((*it1).second == (*it2).second) continue;
			else return false;
		}
		return true;
    }
};

int main(){
	string s,t;
	cin >> s >> t;
	Solution sol;
	if(sol.isIsomorphic(s,t)) cout << "true" << endl;
	else cout << "false" << endl;
}
