#include<iostream>
#include<vector>
#include<queue>
//1. If all integer numbers from the stream are between 0 and 100, how would you optimize it?
//2. If 99% of all integer numbers from the stream are between 0 and 100, how would you optimize it?

using namespace std; 
class MedianFinder {
public:
    /** initialize your data structure here. */
    MedianFinder() {
        
    }
    
    void addNum(int num) {
    	int tmp;
        max_heap.push(num);
        tmp = max_heap.top();
        max_heap.pop();
        min_heap.push(tmp);
        if(min_heap.size() > max_heap.size() + 1){ //保证min_heap保存比max_heap多一个数 或size相等 
        	tmp = min_heap.top(); //调整后相等 
        	min_heap.pop();
        	max_heap.push(tmp);
		}
    }
    
    double findMedian() {
        if(min_heap.size() == max_heap.size()){
        	return (min_heap.top()+max_heap.top())/2.0;
		}
		return min_heap.top(); //返回多出来的数 
    }
private:
	priority_queue<int, vector<int>, greater<int>> min_heap;  //right
	priority_queue<int, vcetor<int>, less<int>> max_heap; //left
};

using namespace std; 
class MedianFinder {
public:
    /** initialize your data structure here. */
    MedianFinder() {
        
    }
    
    void addNum(int num) {
    	int tmp;
        max_heap.push(num);
        tmp = max_heap.top();
        max_heap.pop();
        min_heap.push(tmp);
        if(min_heap.size() > max_heap.size()){//保证maxheap比minheap多一个数或相等 
        	tmp = min_heap.top();//min减1，max+1， 
        	min_heap.pop();
        	max_heap.push(tmp);
		}
    }
    
    double findMedian() {
        if(min_heap.size() == max_heap.size()){
        	return (min_heap.top()+max_heap.top())/2.0;
		}
		return max_heap.top();
    }
private:
	priority_queue<int, vector<int>, greater<int>> min_heap;  //right
	priority_queue<int, vcetor<int>, less<int>> max_heap; //left
};
