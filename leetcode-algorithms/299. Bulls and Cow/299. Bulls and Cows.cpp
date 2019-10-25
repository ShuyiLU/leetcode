#include<iostream>
#include<unordered_map>
#include<cstring>
#include <stdio.h>
#include <stdlib.h>


using namespace std;

class Solution {
public:
    string getHint(string secret, string guess) {
        unordered_map<char, int> count;
        unordered_map<char, int> :: iterator it2;
        unordered_map<int, char> pos;
        unordered_map<int, char> :: iterator it;
        string output = "";
        char str1[100];
        char str2[100];
        for(int i=0; i<secret.length(); i++){
        	pair<int, char> p1 = make_pair(i, secret[i]);
        	pos.insert(p1);
        	count[secret[i]] = count[secret[i]] + 1;
		}
		int A_count = 0;
		int B_count = guess.length();
		for(int i=0; i<guess.length(); i++){
			it = pos.find(i);
			if(guess[i] == (*it).second) {
				A_count++;
				count[guess[i]] = count[guess[i]] - 1;
				pos.erase(i);
			}
		}
		
		
		for(int i=0; i<guess.length(); i++){
			it = pos.find(i);
		//	cout << pos.count(i) << endl;
			if(it == pos.end()) {
				B_count --;
				continue;
			}
			else if(it != pos.end()){
				it2 = count.find(guess[i]);
				if(it2 == count.end()) B_count--;
				else if((*it2).second == 0) B_count--;
				else count[guess[i]] = count[guess[i]] - 1;
			}
			
		}
		
		/*
		B_count = 0;
		for(int i=0; i<guess.length(); i++){
			it = pos.find(i);
			if(it!=pos.end()){
				it2 = count.find(guess[i]);
				if(it2 != count.end()){
					B_count ++;
					count[guess[i]] = count[guess[i]] - 1;
				}
			}
		}
		*/
	//	itoa(A_count, str1, 10);
	//	itoa(B_count, str2, 10);
		/*
		output.push_back(string(str1));
		output.push_back(string('A'));
		output.push_back(string(str2));
		output.push_back(string('B'));
		*/
		output = output + to_string(A_count);
		output = output + 'A';
		output = output + to_string(B_count);
		output = output + 'B'; 
		return output;
    }
};

int main(){
	string s1, s2;
	cin >> s1 >> s2;
	Solution sol;
	cout << sol.getHint(s1,s2) << endl;
	return 0;
}


