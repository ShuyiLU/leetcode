#include<iostream>
#include<vector>
#include<map>

using namespace std; 

class MyCalendarTwo {
public:
    MyCalendarTwo() {
        
    }
    
    bool book(int start, int end) {
        mp[start]++;
        mp[end]--;
        int cnt = 0;
        for(it=mp.begin(); it!=mp.end(); it++){
        	cnt+=(*it).second;
        	if(cnt>2){
        		mp[start]--;
        		mp[end]++;
        		return false;
			}
		}
		return true;
        
    }
    
    map<int, int> mp;
    map<int, int> :: iterator it;
};
