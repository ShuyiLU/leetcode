#include<iostream>
#include<queue>

using namespace std;

class KthLargest {
private:
	
	struct cmp {
		bool operator () (int a, int b){
			return a > b;
		}
	};
	
	
	/*
	bool operator<(int a){
		return *this > a;
	}
	*/
	
	priority_queue<int, vector<int>, cmp> q;
	int q_cap;
	//priority_queue<int> q;
	
public:
    KthLargest(int k, vector<int> nums) {
    	q_cap = k;
        int n = nums.size();
		for(int i=0; i<n; i++){
			if(q.size() < k) q.push(nums[i]);
			else{
				if(nums[i] > q.top()){
					q.pop();
					q.push(nums[i]);
				}
			}
		} 
    }
    
    int add(int val) {
    	if(q.size() < q_cap) q.push(val);
        else if(val > q.top()){
        	q.pop();
        	q.push(val);
		}
		return q.top();
    }
};
