#include<iostream>
#include<vector>
#include<set>
#include<map>
#include<cmath>

using namespace std; 

class ExamRoom {
private:
	set<int> s;
	int last_p;
	int max_d;
	int n;
public:
    ExamRoom(int N) {
    	n = N;
    }
    
    int seat() {
       if(s.size() == 0){
       	s.insert(0);
       	return 0;
	   } 
	    int ans = 0;
		set<int> :: iterator it;
		it = s.begin();
		last_p = *it;
		max_d = *it - ans;
		for(; it!=s.end(); it++){
			if((*it - last_p)/2 > max_d){  //相邻的2个人的距离 
				max_d = (*it - last_p)/2;
				ans = last_p + max_d;
			}
			last_p = *it; //更新前一个人 
		}
		if(n-1 - last_p > max_d) ans = n-1;
		s.insert(ans); //if no 0 in set && 
		return ans; 
    }
    
    void leave(int p) {
        s.erase(p);
    }
};

/**
 * Your ExamRoom object will be instantiated and called as such:
 * ExamRoom* obj = new ExamRoom(N);
 * int param_1 = obj->seat();
 * obj->leave(p);
 */
 
 class ExamRoom {
public:
	set<int> s;
	int last_p;
	int max_d;
	int n;
    ExamRoom(int N) {
        n = N;
    }
    
    int seat() {
        if(s.size() == 0){
        	s.insert(0);
        	return 0;
		}
		
		set<int> :: iterator it;
		it = s.begin();
		int res = 0;
		last_p = *it; //s.begin
		max_d = *it; //s.begin 0 or begin;
		for(; it!=s.end(); it++){
			if((*it-last_p)/2 > max_d){
				max_d = (*it-last_p)/2;
				ans = last_p+max_d;
			}
			last_p = *it;
		}
		if(n-1 - last_p > max_d) ans = n-1;
		s.insert(ans);
		return ans;
	}
		
    
    void leave(int p) {
        
    }
};
