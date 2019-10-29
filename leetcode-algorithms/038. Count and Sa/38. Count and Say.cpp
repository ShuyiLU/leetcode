#include<iostream>
#include<algorithm>
#include<string>
#include<map>

using namespace std;

class Solution {
private: 
    map<int, string> mp;
    
    /*
	string say(int n) {
		int a = n;
		int y;
		string res = "";
		string tmp = "";
		while(a>=0){
			y = a%10;
			tmp = tmp + char(y + '0');
			a = a/10;
		}
		for(int i =0; i<tmp.length()/2; i++){
			swap(tmp[i], tmp[tmp.length() - 1 - i]);
		}
		int j = 0;
		while( j <= tmp.length()) {
			int k = j;
			while(tmp[k] != tmp[j]) k++;
				int count = k-j;
				res = res + char(count + '0' ) + tmp[j];
				j++;
			}
		return res;
	}*/
	string say(string s){
		//cout << s << endl;
		string res="";
		int j = 0;
		while( j < s.length()) {
			int k = j + 1;
			while(k<s.length() && s[k] == s[j]) k++;
			int count = k-j;
			res = res + char(count + '0' ) + s[j];
			j = k;
		}
		return res;
	}
	
public:
    string countAndSay(int n){
	if(mp.count(n) > 0) return mp[n];
	string res = "";
	if(n == 1) {
		mp.insert(make_pair(1, "1"));
		return mp[1];
	}
	else{
		res = say(countAndSay(n-1));
		mp.insert(make_pair(n, res));
		return mp[n];
	} 
}
};

int main(){
	int n;
	cin >> n;
	Solution sol;
	cout << sol.countAndSay(n) << endl;
}

 
