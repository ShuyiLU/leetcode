#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

//第二位是下标，原因：第二位是前面比该元素大的元素个数
//因此从大至小排序，第二位实际是距离数组首的距离 

bool cmp(vector<int> &v1, vector<int> &v2){
	if(v1[0] == v2[0]) return v1[1] < v2[1];
	return v1[0] > v2[0];
} 

class Solution {
public:
    vector<vector<int> > reconstructQueue(vector<vector<int> >& people) {
        vector<vector<int> > res;
        if(people.size() == 0) return res;
        sort(people.begin(), people.end(), cmp);
        res.push_back(people[0]);
        vector<vector<int> > :: iterator it;
        for(int i=1; i<people.size(); i++){
        	it = res.begin();
        	res.insert(it+people[i][1], people[i]);
		}
		return res;
    }
};
