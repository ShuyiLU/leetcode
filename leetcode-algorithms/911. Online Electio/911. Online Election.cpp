#include<iostream>
#include<vector>
#include<map>

using namespace std;

class TopVotedCandidate {
public:
	map<int, int> mp; // (person, ticket numbers);
    vector<pair<int, int> > v; // (time, best candidate)
    TopVotedCandidate(vector<int>& persons, vector<int>& times) {
    	int max_cnt = 0;
    	int max_person = 0;
        for(int i=0; i<times.size(); i++){
        	if(mp.count(persons[i])==0) mp[persons[i]] = 1;
        	else mp[persons[i]]++;  
			if(mp[persons[i]] >= max_cnt){
				max_cnt = mp[persons[i]];
				max_person = persons[i];
			} 	
			v.push_back(make_pair(times[i], max_person));
		}
		
    }
    
    int q(int t) {
        int j=0;
       // int ans;
        while(j<v.size()){
        	if(t<v[j].first){
        	//	ans = v[j-1].second;
        		break;
			}
			j++; 
		}
		return v[j-1].second;
    }
};
