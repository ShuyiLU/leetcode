#include<iostream>
#include<vector>
#include<cstring>

using namespace std; 

class Solution {
public:
    int wordsTyping(vector<string>& sentence, int rows, int cols) {
        string s = ""; // new string of sentence
        for(int i=0; i<sentence.size(); i++){
        	s += sentence[i];
        	s += " ";
		}
		int n = s.length();
		int cnt = 0; // input's length already in the screen
		for(int i=0; i<rows; i++){
			cnt += cols;
			if(s[cnt%n] == ' '){
				cnt++;
			}
			else{
				while(s[(cnt-1)%n] != ' ' && cnt>0){
					cnt--;
				}
			}
		}
		return cnt/n;
    }
    
};
