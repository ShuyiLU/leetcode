#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

//�ڶ�λ���±꣬ԭ�򣺵ڶ�λ��ǰ��ȸ�Ԫ�ش��Ԫ�ظ���
//��˴Ӵ���С���򣬵ڶ�λʵ���Ǿ��������׵ľ��� 

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
