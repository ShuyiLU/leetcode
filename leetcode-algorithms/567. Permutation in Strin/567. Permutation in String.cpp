#include<iostream>
#include<cstring>
#include<string>
#include<map>

using namespace std;

/*
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int flag = 0;
        checkPermutaiton(s1, 0, s2, flag);
        if(flag == 1) return true;
        return false;
    }
    
    void checkPermutaiton(string s1, int i, string s2, int &flag){
    	if(i == s1.length()){
    		if(s2.find(s1) != npos){
    			flag = 1;
    			return;
			}
			return;
		}
		if(i>s1.length()) return;
		for(int j=i; j<s1.length(); j++){
			swap(s1[i], s1[j]);
			checkPermutation(s1, i+1, s2, flag);
			swap(s1[i], s1[j]);
		}
		
	}
    
};

*/

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        map<char, int> mp;
        int h=0;
        for(int i=0; i<s1.length(); i++){
        	mp[s1[i]]++;
        	h += s1[i];
		}
		
		
		for(int i=0; i+s1.length()<s2.length(); i++){
			int tmp = 0;
			for(int j=i; j<s1.length(); j++){
				tmp += s2[j];
			}
			if(h != tmp) continue;
			else{
				map<char, int> mp2;
				for(int j=i; j<s2.length(); j++){
					mp2[s2[j]]++;
				} 
				
				if(mp.size() != mp2.size()) continue;
				map<char, int> :: iterator it1, it2;
				int flag = 0;
				for(it1=mp.begin(), it2=mp2.begin(); it1 != mp.end() && it2 != mp2.end(); it1++, it2++){
					if((*it1).first != (*it2).first || (*it1).second != (*it2).second ){
						flag = 1;
						break;
					}
				}
				if(flag == 0) return true;
			}
		}
		
		return false;
    }
};

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n1 = s1.length(), n2 = s2.length();
        vector<int> m1(128, 0);
        vector<int> m2(128, 0);
        for(int i=0; i<n1; i++){
        	m1[s1[i]]++;
        	m2[s2[i]]++;
		}
		if(m1 == m2) return true;
		for(int i=n1; i<n2; i++){
			m2[s2[i]]++;
			m2[s2[i-n1]]--1;
			if(m1 == m2) return true;
			
		}
		return false;
    }
};
