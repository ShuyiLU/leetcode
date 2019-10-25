#include<iostream>
#include<vector> 
#include<map>
#include<queue>

using namespace std;

struct Node{
	int x;
	int y;
	float d;
	Node( int a, int b, float c ):
        x(a), y(b), d(c) {}
};

struct cmp {
	bool operator()(Node a, Node b){
		return a.d < b.d;
	}
	
};

class Solution {	
public:
    vector<vector<int> > kClosest(vector<vector<int> >& points, int K) {
       // priority_queue<pair<vector<int> , float> > q;
       priority_queue<Node, vector<Node>, cmp> q;
        while(!q.empty()) q.pop();
      //  map <vector<int>, float > mp;
      //  map <vector<int>, float > :: iterator it;
        //vector<float> dis;
        for(int i=0; i<points.size(); i++){
        	float d = points[i][0] * points[i][0] + points[i][1] * points[i][1];
        //	dis.push_back(d);
        //	pair<vector<int> , float> p = make_pair(points[i],d);
        	Node p = Node(points[i][0], points[i][1], d);
        	//mp.insert(make_pair(points[i],d));
        	if(q.size() < K) q.push(p);
        	else{
        		if(q.top().d < d) continue;
        		else{
        			q.pop();
        			q.push(p);
				}
			}
		}
		
		//int tmp = q.top();
		vector<vector<int> > re;
		while(!q.empty()){
			//float tmp = q.top();
			//for(it=mp.begin(); it!=mp.end(); it++){
			//	if(it->second == tmp) re.push_back(it->first);
			//}
		//	pair<vector<int> , float> tmp = q.top();
			Node tmp = q.top();
			vector<int> tmp_v;
			tmp_v.push_back(tmp.x);
			tmp_v.push_back(tmp.y);
			re.push_back(tmp_v);
			tmp_v.clear();
			q.pop();
		}
		
		
	
		return re;
    }
};

int main(){
	vector<int> v1;
	v1.push_back(-5);
	v1.push_back(4);
	vector<int> v2;
	v2.push_back(-6);
	v2.push_back(-5);
	vector<int> v3;
	v3.push_back(4);
	v3.push_back(6);
	vector<vector<int> > v;
	v.push_back(v1);
	v.push_back(v2);
	v.push_back(v3);
	vector<vector<int> > re;
	Solution sol;
	re = sol.kClosest(v,2);
	for(int i=0; i<re.size();i++){
		for(int j=0; j<re[i].size();j++){
			cout << re[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}
