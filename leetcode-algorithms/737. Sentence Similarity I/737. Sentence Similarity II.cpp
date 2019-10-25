#include<iostream>
#include<unordered_map>
#include<vector>
#include<cstring>
#include<set>
#include<map>

using namespace std;

class Solution {
private:
	int fa[4001];
	int findUnion(int k){
		if(fa[k] == -1) return k;
		else return fa[k] = findUnion(fa[k]);
	}
	
	void merge(int i, int j){
		int fa1 = findUnion(i);
		int fa2 = findUnion(j);
		if(fa1 != fa2){
			fa[fa1] = fa2;
		}
	}
public:
    bool areSentencesSimilarTwo(vector<string>& words1, vector<string>& words2, vector<pair<string, string> > pairs) {
        set<string> p;
        int len1 = words1.size();
        int len2 = words2.size();
        if(len1 != len2) return false;
        map<string, int> mp;
        map<string, int> :: iterator it1;
        map<string, int> :: iterator it2;
        int k = 1;
        for(int i=0; i<4001; i++) fa[i] = -1;
        for(int i=0; i<pairs.size(); i++){
        	p.insert(pairs[i].first);
        	p.insert(pairs[i].second);
        	it1 = mp.find(pairs[i].first);
        	if(it1 == mp.end()) {
        		mp.insert(make_pair(pairs[i].first, k));
        		k++;
			}
        	it2 = mp.find(pairs[i].second);
        	if(it2 == mp.end()) {
        		mp.insert(make_pair(pairs[i].second, k));
        		k++;
			}
        	merge(mp[pairs[i].first],mp[pairs[i].second]);
		}
       int p1, p2;
		for(int i=0; i<len1; i++){
			if(words1[i] == words2[i]) continue;
			else{
				if(p.count(words1[i]) == 0) return false;
				else{
					p1 = mp[words1[i]];
					p2 = mp[words2[i]];
					if(findUnion(p1) != findUnion(p2)) return false;
				}
			}
		}
		return true;
    }
};

int main(){
	int n, m;
	cin >> n >> m;
	string a;
	vector<string> v1;
	vector<string> v2;
	vector<pair<string, string> >p;
	for(int i=0; i<n; i++){
		cin >> a;
		v1.push_back(a);
	}
	for(int j=0; j<m; j++){
		cin >> a;
		v2.push_back(a);
	}
	int k;
	cin >> k;
	string s1, s2;
	for(int i=0; i<k; i++){
		cin >> s1 >> s2;
		p.push_back(make_pair(s1,s2));
	}
	Solution sol;
	if(sol.areSentencesSimilarTwo(v1, v2, p)) cout << "true" << endl;
	else cout << "false" << endl;
	return 0;
}


