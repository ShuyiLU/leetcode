#include<iostream>
#include<algorithm>
#include<vector>

using namespace std; 

class MaxStack {
private:
	vector<int> v;
public:
    /** initialize your data structure here. */
    MaxStack() {
        
    }
    
    void push(int x) {
        v.push_back(x);
    }
    
    int pop() {
    	if(v.size() == 0) return -1;
        int res = v[v.size()-1];
        v.erase(v.begin()+v.size()-1);
        return res;
    }
    
    int top() {
    	if(v.size() == 0) return -1;
        return v[v.size()-1];
    }
    
    int peekMax() {
    	if(v.size() == 0) return -1;
        int res = v[v.size()-1];
      //  int pos = v.size()-1;
        for(int i=v.size()-1; i>=0; i--){
        	if(res < v[i]) {
        		res = v[i];
			//	pos = i;	
			}
		}
		return res;
    }
    
    int popMax() {
        if(v.size() == 0) return -1;
        int res = v[v.size()-1];
        int pos = v.size()-1;
        for(int i=v.size()-1; i>=0; i--){
        	if(res < v[i]) {
        		res = v[i];
				pos = i;	
			}
		}
		v.erase(v.begin() + pos);
		return res;
    }
};

/**
 * Your MaxStack object will be instantiated and called as such:
 * MaxStack* obj = new MaxStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->peekMax();
 * int param_5 = obj->popMax();
 */
