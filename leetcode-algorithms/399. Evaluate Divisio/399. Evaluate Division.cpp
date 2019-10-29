#include<iostream>
#include<cstring>
#include<unordered_map>
#include<vector>
#include<set>
#include<map>

using namespace std;

class Solution {
public:
    vector<double> calcEquation(vector<pair<string, string> > equations, 
								vector<double>& values, vector<pair<string, string> > queries) {
        map<pair<string, string>, double> mp;
        map<pair<string, string>, double> :: iterator fin1;
        map<pair<string, string>, double> :: iterator fin2;
        map<pair<string, string>, double> :: iterator it;
        set<string> point;
        for(int i=0; i<equations.size(); i++){
        	mp.insert(make_pair(equations[i] , values[i]) );
        	point.insert(equations[i].first);
        	point.insert(equations[i].second);
        	mp.insert(make_pair(make_pair(equations[i].second, equations[i].first) , 1.0/values[i]));
        	it = mp.find(make_pair(equations[i].first, equations[i].first));
        	if(it == mp.end()){
        		mp.insert(make_pair(make_pair(equations[i].first, equations[i].first), 1.0));
			}
			else continue;
		}
		set<string> :: iterator it_k;
		set<string> :: iterator it_i;
		set<string> :: iterator it_j;
		for(it_k=point.begin(); it_k!=point.end(); it_k++){
			for(it_i=point.begin(); it_i!=point.end(); it_i++){
				for(it_j=point.begin(); it_j!=point.end(); it_j++){
					pair<string, string> pair1 = make_pair((*it_i),(*it_k));
					pair<string, string> pair2 = make_pair((*it_k),(*it_j));
					if(mp.count(pair1) > 0 && mp.count(pair2) > 0){
						fin1 = mp.find(pair1);
						fin2 = mp.find(pair2);
						double tmp = (*fin1).second * (*fin2).second;
						mp.insert(make_pair(make_pair((*it_i),(*it_j)), tmp));
						mp.insert(make_pair(make_pair((*it_j),(*it_i)), 1/tmp));
					}
				}
			}
		}		
		
		vector<double> output;
		for(int i=0; i<queries.size(); i++){
			map< pair<string, string>, double > :: iterator toFind;
			toFind = mp.find(queries[i]);
			if(toFind == mp.end()) output.push_back(-1);
			else output.push_back((*toFind).second);
		}
		return output;
    }
};

int main(){
	
	
} 

/*
unordered_map< pair<string, string> > equ_mp;
		unordered_map< pair<string, string> > :: iterator it2;
		for(int i=0; i<equations.size(); i++) {
			equ_mp.insert(equations[i]);
			equ_mp.insert(make_pair(equations[i].second, equations[i].first));
			it2 = equ_mp.find(make_pair(equations[i].first, equations[i].first));
			if(it2 == equ_mp.end()){
        		equ_mp.insert(make_pair(equations[i].first, equations[i].first));
			}
		}
*/

/*
		for(auto: val_k: mp){
			for(auto: val_i : mp){
				for(auto: val_j : mp){
					if(mp.count(make_pair(val_i.first.first, val_k.first.first) ) > 0 && mp.count(val_k.first.second, val_j.first.second) ) > 0 ){
						fin1 = mp.find(make_pair(val_i.first.first, val_k.first.first) );
						fin2 = mp.find(make_pair(val_k.first.second, val_j.first.second) );
						double tmp = (*fin1).second * (*fin2).second;
						mp.insert(make_pair(val_i.first, val_j.second), tmp);
					}
				}
			}
		}
		*/
		
		/*
		for(int k=0; k<mp.size(); k++){
			for(int i=0; i<mp.size(); i++){
				for(int j=0; j<mp.size(); j++){
					pair<string, string> pair1 = make_pair(mp[i].first.first, mp[k].first.first);
					pair<string, string> pair2 = make_pair(mp[k].first.second, mp[j].first.second);
					if(mp.count(pair1) > 0 && mp.count(pair2) > 0){
						fin1 = mp.find(pair1);
						fin2 = mp.find(pair2);
						double tmp = (*fin1).second * (*fin2).second;
						mp.insert(make_pair(mp[i].first.first, mp[j].first.second) , tmp);
					}
				}
			}
		}
		*/
