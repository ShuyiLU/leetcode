#include<iostream>
#include<queue>

using namespace std;

class MovingAverage {
private:
	queue<int> q;
	double sum;
	int len;
public:
    /** Initialize your data structure here. */
    MovingAverage(int size) {
    	sum = 0;
    	len = size;
        //if(q.size() >= size) q.pop();
    }
    
    double next(int val) {
        double res;
        //vector<int> v;
        q.push(val);
        sum = sum + val;
        if(q.size() > len){
        	sum = sum - q.front();
        	q.pop();
		}
		res = sum / len;
		return res;
    }
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage obj = new MovingAverage(size);
 * double param_1 = obj.next(val);
 MovingAverage m = new MovingAverage(3);
m.next(1) = 1
m.next(10) = (1 + 10) / 2
m.next(3) = (1 + 10 + 3) / 3
m.next(5) = (10 + 3 + 5) / 3
 */

