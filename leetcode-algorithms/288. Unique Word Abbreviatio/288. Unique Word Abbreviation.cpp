#include<iostream>
#include<vector>
#include<set>
#include<map>
#include<cstring>

using namespace std;

/*
struct abb{
	int len;
	char front;
	char tail;
	abb(int l, char f, char t):len(l), front(f), tail(t) {}
};

bool cmp(abb a, abb b){
	if(a.len == b.len && a.front == b.front && a.tail==b.tail) return true;
	else return false;
}

class ValidWordAbbr {
public:
	vector<abb> v;
	set<int> s;
    vector<string> d;
    ValidWordAbbr(vector<string>& dictionary) {
        d = dictionary;
        for(int i=0; i<dictionary.size(); i++){
        	int len = dictionary[i].length();
        	s.insert(len);
        	v.push_back(abb(len, dictionary[i][0], dictionary[i][len-1]));
		}
    }
    
    bool isUnique(string word) {
    	if(s.count(word.length()) == 0) return true;
        abb tmp = abb(word.length(), word[0], word[word.length()-1]);
       	for(int i=0; i<v.size(); i++){
       		if(cmp(tmp, v[i]) && word != d[i]) return false;
		}
		return true;
    }
};
*/
class ValidWordAbbr {
public:
	map<string, string> mp;
    ValidWordAbbr(vector<string>& dictionary) {
        for(int i=0; i<dictionary.size(); i++){
        	string tmp = dictionary[i];
        	mp[tmp] = to_string(tmp.length()) + tmp[0] + tmp[tmp.length()];
		}
    }
    
    bool isUnique(string word) {
        string tmp = to_string(word.length()) + word[0] + word[word.length()];
        map<string, string> :: iterator it;
        for(it=mp.begin(); it!=mp.end(); it++){
        	if((*it).first != word && (*it).second == tmp) return false;
		}
		return true;
    }
};

