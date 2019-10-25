#include<iostream>
#include<string>
#include<vector> 
#include<algorithm>
#include<map>

using namespace std;

class Solution {
public:
    bool isStrobogrammatic(string num) {
   		map <char, char> mp;
		mp.insert(make_pair('0','0'));
		mp.insert(make_pair('1','1'));
		mp.insert(make_pair('8','8'));
		mp.insert(make_pair('6','9'));
		mp.insert(make_pair('9','6'));
		string tmp;
		for(int i =0; i<num.length(); i++){
			if(mp.count(num[i]) == 0) return false;
			else{
				tmp.resize(num.length());
				//map<char, char> :: iterator it;
				//it = mp.find(num[i]);
				tmp[i] = mp[num[i]];
			}
		}
		for(int i =0; i<num.length(); i++){
			if(num[i] != tmp[num.length()-i-1]) return false;
		}
	return true;
    }
};

int main(){
	string s;
	cin >> s;
	Solution sol;
	if(sol.isStrobogrammatic(s)) cout << "true" << endl;
	else cout << "false" << endl;
	return 0;
}

