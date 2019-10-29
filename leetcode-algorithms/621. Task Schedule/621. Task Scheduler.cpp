#include<vector>
#include<iostream>
#include<map>
#include<algorithm>

using namespace std;

class Solution {
	
public:
	static bool compare (pair<char, int> p1, pair<char, int>p2){
		return p1.second > p2.second;
	}
	
    int leastInterval(vector<char>& tasks, int n) {
    	int flag_o = 0;
    	int count = 0;
        map < char, int> mp;
        map < char, int > :: iterator it;
        if(tasks.size() == 0) return 0;
        if(tasks.size() == 1) return 1;
       vector<pair<char, int> > mp_v;
        for(int i=0; i<tasks.size(); i++){
        	if(mp.count(tasks[i]) == 0) mp[tasks[i]] = 1;
        	else mp[tasks[i]] += 1;
		}
		for(it=mp.begin(); it!=mp.end(); it++){
			mp_v.push_back(*it);
		}
		
		sort(mp_v.begin(), mp_v.end(), compare);
		//for(int i = 0; i < mp_v.size(); i++) cout << mp_v[i].first <<" " << mp_v[i].second << endl;
		
		int size = mp_v.size();
		if(size == 1){
			count = (mp_v[0].second - 1 ) * (n+1) + 1;
			return count;
		}
		int group = mp_v[0].second;
		if(mp_v[0].second > mp_v[1].second){
			group -=1 ;
			mp_v[0].second -= 1;
			flag_o = 1;
		//	cout << "dd" << endl;
		} 
		int flag = 0;
		
		vector< vector<char> > temp;
		temp.resize(group); 
		
		//
		
		for(int i=0; i<mp_v.size(); i++){
			
			while(mp_v[i].second > 0){
				
				if(flag > group-1) flag = 0;
				
				temp[flag].push_back(mp_v[i].first);
				mp_v[i].second -= 1;				
				flag ++;
				
			}
		}
		/*
		cout << temp.size() <<endl;
		for(int i=0; i<temp.size(); i++){
			//for(int j=0; j<temp[i].size(); j++) cout << temp[i][j] << " ";
			cout <<temp[i].size() << " ";
			for(int j=0; j<temp[i].size(); j++) cout << temp[i][j] << " ";
			cout << endl;
		}
		*/
		
		for(int i=0; i<temp.size()-1; i++){
			if(temp[i].size() < n+1) count += (n+1);
			else count += temp[i].size();
			//cout << "aa" << endl;
		}
	
		if(flag_o == 1){
			if(temp[group-1].size() < n+1) count += (n+1);
			else count += temp[group-1].size();
			count +=1 ;
			//cout << "bb" << endl;
		} 
		else {
			//cout << "cc" << endl;
			count += temp[group-1].size();
		}
	
		return count;
		
    }
};

int main(){
	int n,k;
	cin >> n >> k;
	vector<char> v;
	char a;
	for(int i=0; i<n; i++){
		cin >> a;
		v.push_back(a);
	}
	Solution sol;
	cout << sol.leastInterval(v,k) << endl;
	
}
