#include<iostream>
#include<algorithm>
#include<string> 
using namespace std;
class Solution {
public:
    bool canTransform(string start, string end) {
        if(start.length() != end.length()) return false;
		if(start.length() == 0 && end.length() == 0) return true;
		for(int i=0; i<start.length(); i++){
			if(start[i] == 'R' && end[i] == 'X'){
				for(int j=i+1; j<start.length(); j++){
					if(start[j] != 'X' && j==start.length()-1) return false;
					if(start[j] == 'X') {
						swap(start[i], start[j]);
						break;
					}
				}
			}	
		}
		for(int i=start.length()-1; i>=0; i--){
			if(start[i] == 'L' && end[i] == 'X'){
				for(int j=i-1; j>=0; j--){
					if(start[j]!='X' && j==0) return false;
					if(start[j] == 'X') {
						swap(start[i], start[j]);
						break;
					}
				}
			}	
		}
for(int i =0; i<start.length(); i++){
	if(start[i] != end[i]) return false;
}
return true;
    }
};

