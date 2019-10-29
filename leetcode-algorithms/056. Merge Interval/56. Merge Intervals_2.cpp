#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

bool Less (vector<int> v1, vector<int> v2){
	return v1[0] < v2[0];
}

	struct cmp{
		bool operator()(const vector<int> &a, const vector<int> &b){
			return a[1] > b[1];
		}

	};

class Solution {
public:
    vector<vector<int> > merge(vector<vector<int> >& intervals) {
        sort(intervals.begin(), intervals.end(), Less);
        priority_queue<vector<int>, vector<vector<int> >, cmp) q;
        for(int i=0; i<intervals.size(); i++){
        	if(q.empty()) q.push(intervals[i]);
        	if(intervals[i][0] <= q.top()[1]){
        		vector<int> tmp(2, -1);
        		tmp[0] = min(intervals[i][0], q.top()[0]);
        		tmp[1] = max(intervals[i][1], q.top()[1]);
        		q.pop();
        		q.push(tmp);
			}
			else{
				q.push(intervals[i]);
			}
		}
		vector<vector<int> > ans;
		while(!q.empty()){
			ans.push_back(q.top());
			q.pop();
		}
		return ans;
    }
};
