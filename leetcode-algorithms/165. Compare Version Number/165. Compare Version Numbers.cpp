#include<iostream>
#include<vector>
#include<cstring> 

class Solution {
public:
    int compareVersion(string version1, string version2) {
        int n = version1.length();
        int m = version2.length();
        int i1 = 0, i2 = 0, j1 = 0, j2 = 0;
        string s1, s2;
        while(i2<n && j2<m){
        	while(i2<n && version1[i2] != '.' ){
        		i2++;
			}
        	while(j2<m && version2[j2] != '.'){
        		j2++;
			}
        	s1 = version1.substr(i1, i2-i1);
            s2 = version2.substr(j1, j2-j1);
  
        	if(atoi(s1.c_str()) > atoi(s2.c_str())) return 1;
        	else if(atoi(s1.c_str()) < atoi(s2.c_str())) return -1;
        	i1 = i2+1;
        	i2++;
        	j1 = j2+1;
        	j2++;
        	
		}

     //   cout << i2 << " " << n << endl;
     //   cout << j2 << " " << m << endl;
		if(i2 < n){
			while(i2<n){
				if(version1[i2] != '0' && version1[i2] != '.') return 1;
				i2++;
			}
             return 0;
        }
		if(j2 < m){
			while(j2<m){
				if(version2[j2] != '0' && version2[j2] != '.') return -1;
				j2++;
			}
             return 0;
        }
		return 0;
    }
};
