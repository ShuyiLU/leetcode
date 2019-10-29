#include<iostream>
#include<string>
#include<vector> 
#include<algorithm>
#include<map>
#include<set>

using namespace std;

class Solution {
public:
int minAreaRect(vector<vector<int> >& points) {
	int min = 1600000000;
    set< pair<int, int>  > s;
    int flag = 0;
	for( int i = 0; i<points.size(); i++){
		pair<int, int> tmp = make_pair(points[i][0], points[i][1]);
	    s.insert(tmp);
	}
	for(int i = 0; i<points.size(); i++){
		for(int j=i+1; j<points.size(); j++){
			if(points[i][0] == points[j][0] || points[i][1] == points[j][1]) continue;
			pair<int, int> p1 = make_pair(points[i][0], points[j][1]);
			if(s.count(p1) == 0) continue;
	 		pair<int, int> p2 = make_pair(points[j][0], points[i][1]);
			if(s.count(p2) == 0) continue;
			int are = abs(points[i][0] - points[j][0]) * abs(points[i][1] - points[j][1]);
			if(are < min) min = are;
			flag = 1;
		}
	}
	if(flag == 0) return 0;
	return min;
    }
};

