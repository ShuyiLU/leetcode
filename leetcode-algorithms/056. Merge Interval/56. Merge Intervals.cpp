#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;



//Definition for an interval.
struct Interval {
      int start;
      int end;
      Interval() : start(0), end(0) {}
      Interval(int s, int e) : start(s), end(e) {}
  };
  
bool Less(Interval i1, Interval i2){
	return i1.start < i2.start;
}
 
class Solution {
public:
    vector<Interval> merge(vector<Interval>& intervals) {
    	sort(intervals.begin(),intervals.end(), Less);
    	if(intervals.empty())return vector<Interval>() ;
    	vector<Interval> :: iterator it;
        vector<Interval> output;
        Interval tmp = Interval(intervals[0].start,intervals[0].end);
        for(it=intervals.begin(); (it+1)!=intervals.end();it++){
        	if((*(it+1)).start <= tmp.end){
        		int max = tmp.end;
        		if((*(it+1)).end > tmp.end) max = (*(it+1)).end;
        		tmp = Interval((*it).start,max);
        		intervals.erase(it+1);
        		it--;
			}
			else{
				output.push_back(tmp);
				tmp = Interval((*(it+1)).start,(*(it+1)).end);
			}
		}
		output.push_back(tmp);
		return output;
    }
};
