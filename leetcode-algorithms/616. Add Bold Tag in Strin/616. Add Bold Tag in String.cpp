#include<iostream>
#include<cstring>
#include<vector>
#include<algorithm>
#include<string>
#include<queue>

class Solution {
public:
    string addBoldTag(string s, vector<string>& dict) {
    	string ans = "";
    //	map<int, int> mp; //(index, len)
    	vector<pair<int, int> > v;
        for(int i=0; i<dict.size(); i++){
        	string t = dict[i];
        	size_t p = s.find(t);
        	if(p == s.npos) continue;
        	else{
        		v.push_back(make_pair(p, p+t.length()));
			}
		}
		vector<pair<int, int> > r = merge(v);
		//vector<pair<int, int> > :: iterator it;
		for (auto it = r.rbegin(); it != r.rend(); ++it) {
            s.insert(it->second, "</b>");
            s.insert(it->first, "<b>");
        }
        return s;
				
    }
    
    vector<pair<int, int> > merge(vector<pair<int, int> > v){
    	vector<pair<int, int>> r;
    	sort(v.begin(), v.end(), compare);
    	for(int i=0, j=-1; i<v.size(); ++i){
    		if(j<0 || v[i].first > r[j].second){
    			r.push_back(v[i]);
    			++j;
			}
			else{
				r[j].second = max(r[j].second, v[i].second);
			}
		}
		return r;
	}
    
private:
	static bool compare(pair<int, int> &a, pair<int, int> &b) {
        return a.first < b.first || a.first == b.first && a.second < b.second;
    }

};
