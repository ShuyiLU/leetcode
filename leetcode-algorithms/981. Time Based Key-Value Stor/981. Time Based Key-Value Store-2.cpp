#include<iostream>
#include<map>

using namespace std;


class TimeMap {
private:
	map<string, map<int, string> > mp;
public:
    /** Initialize your data structure here. */
    TimeMap() {
        mp.clear();
    }
    
    void set(string key, string value, int timestamp) {
        mp[key][timestamp] = value;
    }
    
    string get(string key, int timestamp) {
    	string res = "";
        if(mp.count(key) == 0) return "";
        else{
        	map<int, string> tmp = mp[key];
        	map<int, string> :: iterator it;
        	for(it=tmp.begin(); it!=tmp.end(); it++){
        		if(timestamp >= (*it).first) res= (*it).second;
        		else return res;
			}
		}
    }
};
