#include<iostream>
#include<set>
#include<map>
#include<algorithm>

using namespace std;


class Solution {
public:
    int numberOfBoomerangs(vector<pair<int, int>>& points) {
    	if(points.empty()) return 0;
        int count = 0;
        double d;
        set<pair<pair<int, int> , double> >p_d;
        map<pair<pair<int,int>, double>, int > mp; //mp[i] = ( (point,d), count)
        for(int i=0; i<points.size(); i++){
        	while(!mp.empty()) mp.clear();
        	for(int j=0; j<points.size(); j++){
        		if(i!=j){
        			d = sqrt((points[i].first - points[j].first) * (points[i].first - points[j].first) + 
					         (points[i].second - points[j].second) * (points[i].second - points[j].second) );
					pair<pair<int, int>, double> tmp = make_pair(points[i], d);
					if(p_d.count(tmp) > 0 ){
						mp[tmp] = mp[tmp] + 1;
					}
					else{
						p_d.insert(tmp);
						mp.insert(make_pair(tmp, 1) );
					}
				}
			}
			map<pair<pair<int,int>, double>, int > :: iterator it;
			for(it = mp.begin(); it!=mp.end(); it++){
				if((*it).second>1){
					count = count + ((*it).second * ((*it).second - 1));
				}
				
			}
		}
		return count;
    }
};



class Solution {
public:
    int numberOfBoomerangs(vector<pair<int, int>>& points) {
        map<int,int> mp; // map[i] : for current point, 1:distance, 2:count
        int count = 0;
        int d;
        for(int i=0; i<points.size(); i++){
        	while(!mp.empty()) mp.clear();
        	for(int j=0; j<points.size(); j++){
        		if(i!=j){
        			d = (points[i].first - points[j].first) * (points[i].first - points[j].first) + 
					         (points[i].second - points[j].second) * (points[i].second - points[j].second) ;
					if(mp.count(d)>0){
						mp[d] = mp[d] + 1; 
					}
					else{
						mp.insert(make_pair(d,1));
					} 
				}
			}
			map<int,int> :: iterator it;
			for(it=mp.begin(); it!=mp.end(); it++){
				if((*it).second>1) count = count + ((*it).second * ((*it).second - 1));
			}
		}
		return count;
    }
};


int main(){
	int n;
	cin >> n;
	int x,y;
	vector<pair<int, int> > v;
	for(int i=0; i<n; i++){
		cin >> x >> y;
		v.push_back(make_pair(x,y));
	}
	Solution sol;
	cout << sol.numberOfBoomerangs(v) << endl;
	return 0;
}
