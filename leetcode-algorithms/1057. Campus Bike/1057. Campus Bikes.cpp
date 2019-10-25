#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<set>
#include<map>

using namespace std;

struct d{
	int val;
	int w_index;
	int b_index;
	d(int a, int b, int c) : val(a), w_index(b), b_index(c){}
};

struct cmp{
	bool operator () (const d*& d1,const d*& d2){
		return d1->val < d2->val;
	}
	
};

class Solution {
public:
    vector<int> assignBikes(vector<vector<int> >& workers, vector<vector<int> >& bikes) {
        int n = workers.size();
        int m = bikes.size();
        map<int, int> mp;
        vector<int> ans;
        ans.resize(n);
		vector<d*> tmp;
		
		for(int i=0; i<n; i++){
			for(int j=0; j<m; j++){
				int t = dis(workers[i], bikes[j]);
				tmp.push_back(new d(t,i,j));
			}
		}
		
		sort(tmp.begin(), tmp.end(), cmp);
		
		set<int> w_s, b_s;
		
		for(int i=0; i<tmp.size(); i++){
			d* t_d = tmp[i];
			if(w_s.count(t_d->w_index)>0 || b_s.count(t_d->b_index)>0) continue;
			w_s.insert(t_d->w_index);
			b_s.insert(t_d->b_index);
			mp[t_d->w_index] = t_d->b_index;
		}
		map<int, int> :: iterator it;
		for(it=mp.begin(); it!=mp.end(); it++){
			ans.push_back((*it).second);
		}
		return ans;
        
    }
    
    int dis(vector<int> w, vector<int> b){
    	return abs(w[0]-b[0]) + abs(w[1]-b[1]);
	}
    
};
