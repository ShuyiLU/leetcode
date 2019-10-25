#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
#include<cstring>
#include<set>

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
        map<int, string>& tmp = mp[key];
        map<int, string> :: iterator it = tmp.upper_bound[timestamp];  // upper_bound： 比tmp[key]的key大的后一个 
        if(it == tmp.begin()) return "";
        else{
        	it--;
        	return it->second;
		}
    }
};


/*
class TimeMap {
private:
	vector<vector<int> > v;
	vector<int> time;
	map<pair<string, int> , string> mp;
	set<string> kw;   //keywprd has appeared 
	map<string, int> kw_label;  //key ana the order of key
public:

    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        if(kw.count(key) == 0){
    		kw.insert(key);
    		vector<int> tmp;
    		tmp.clear();
    		v.push_back(tmp);
    		kw_label[key] = v.size()-1;
		}
		time = v[kw_label[key]];
        mp[make_pair(key, timestamp)] = value;
        time.push_back(timestamp);
        sort(time.begin(), time.end());
    }
    
    string get(string key, int timestamp) {
        if(kw.count(key) == 0) return "";
    	time = v[kw_label[key]];
        int len = time.size();
        if(len == 0) return "";
        if(len == 1) {
        	if(timestamp < time[0]) return "";
        	else return mp[make_pair(key, time[0])];
		}
        int l = 0; 
        int r = len-1;
        int mid;
        while(l < r && r-l>1 && r < len){
        	mid = (l+r)/2;
        	if(time[mid] == timestamp){
        		return mp[make_pair(key, time[mid])];
			}
			
			else if(time[mid] > timestamp){
				r = mid;
			}
			
			else{
				l = mid;
			}
		}
		
		if(timestamp < time[l]) return "";
		if(timestamp == time[l]) return mp[make_pair(key,time[l])];
		if(timestamp >= time[r]) return mp[make_pair(key, time[r])];
		
		return mp[make_pair(key, time[l])];
		
    }
};
*/


/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */
