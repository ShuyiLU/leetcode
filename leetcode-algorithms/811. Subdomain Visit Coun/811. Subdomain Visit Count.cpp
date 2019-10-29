#include<iostream>
#include<cstring>
#include<vector>
#include<map>

using namespace std;

class Solution {
public:
    vector<string> subdomainVisits(vector<string>& cp) {
        int n = cp.size();
        if(n == 0) return vector<string>{};
        vector<string> v;
        map<string, int> mp;
        for(int i=0; i<n; i++){
        	string s = cp[i];
        	
        	for(int j=0; j<s.length(); j++){
        		int num=0;
        		int flag = 0;
        		if(s[j] != ' ' && flag == 0){
        			num = num*10 + int (s[j] - '0');
				} 
        		else if(s[j] == ' '){
        			flag = 1;
        			continue;
				} 
			
        		else{
        			int k=j;
        			
        			if(mp.count(s.substr(j, s.length()-j)) == 0) mp[s.substr(j, s.length()-j)] = 0;
					mp[s.substr(j, s.length()-j)] += num;
					
        			
        			while(k<s.length()){
        				string t="";
        				if(s[k] != '.') {
        					t += s[k];
							k++;	
						}
        				else{
        					if(mp.count(s.substr(k+1, s.length()-k-1)) == 0) mp[s.substr(k+1, s.length()-k-1)] = 0;
        					mp[s.substr(k+1, s.length()-k-1)] += num;
        					k++;
						}
					}
					
					j = s.length();
				}
							
			}
			
			map<string, int > :: iterator it;
			for(it=mp.begin(); it!=mp.end(); it++){
				cout << it->first << " " << it->second << endl;
			}
			
			
			/*
			for(it=mp.begin(); it!=mp.end(); it++){
				string st = to_string(it->second) + " " + it->first;
				v.push_back(st);
			}
			*/
			
		}
		return v;
    }
};
