#include<iostream>
#include<queue>
#include<algorithm>

using namespace std;

// * Definition for an interval.
struct Interval {
     int start;
     int end;
     Interval() : start(0), end(0) {}
     Interval(int s, int e) : start(s), end(e) {}
 };
 
bool operator> (const Interval &a, const Interval &b ){  
       return a.end > b.end;//  使用">"则为小根堆  
}  

bool Less(const Interval &a, const Interval &b){
	return a.start < b.start;
}
 
class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        int count = 0;
        if(intervals.empty()) return count;
        sort(intervals.begin(), intervals.end(), Less);
        priority_queue<Interval, vector<Interval>, greater<Interval> > q;
        q.push(intervals[0]);
        count = count + 1;
        for(int i=1; i<intervals.size(); i++){
        	if(intervals[i].start >= q.top().end){
        		Interval tmp = Interval(q.top().start, intervals[i].end);
        		q.pop();
        		q.push(tmp);
			}
			else{
				count++ ;
				q.push(intervals[i]);
			}
			//cout << count;
		}
	/*	while(!q.empty()){
			Interval in = q.top();
			cout << in.start << " " << in.end << endl;
			q.pop();
		} */
        return count;
    }
};

int main(){
	int n;
	cin >> n;
	int a, b;
	vector<Interval> v;
	for(int i=0; i<n; i++){
		cin >> a >> b;
		Interval in = Interval(a, b);
		v.push_back(in);
	}
	Solution solution;
	cout << solution.minMeetingRooms(v) << endl; 
	return 0;
}
