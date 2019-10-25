#include<iostream>
#include<vector>
#include<cstring>
#include<map>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<char, int> mp;
		if(s.length() == 0 || s.length() == 1) return s.length();
        int i=0, j=0;
        int max = 0;
        int max_i = 0;
        int max_j = 0;
        int len = 0;
        int flag = 1;
        while(i<s.length() && j<s.length()){
        	//cout << i << " " << j << endl;
        	if(flag == 1){
        		if(mp.count(s[j]) == 0) mp[s[j]] = 1;
        		else mp[s[j]] += 1;
			}
      	
        	if(mp[s[j]] >= 2){
        		if(len > max){
        			max = len;
        		//	max_i = i;
        		//	max_j = j-1;
        		//	cout << max_i << " " << max_j << endl;
				} 
				
        		len--;
        		mp[s[i]] -= 1;
        		i++;
        		flag = 0;
     		
			}
			else{
				flag = 1;
				j++;
				len++;	
			}			
		}
		if(len > max) max = len;
        return max;      
    }
};

int main(){
	string s;
	cin >> s;
	Solution sol;
	cout << sol.lengthOfLongestSubstring(s) << endl;
	return 0;
}
