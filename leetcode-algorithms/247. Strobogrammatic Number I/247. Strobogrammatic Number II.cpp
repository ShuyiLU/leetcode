#include<iostream>
#include<string>
#include<vector> 
#include<algorithm>
#include<map>

using namespace std;

/*

class Solution {
private:
	vector<string> output;
	vector<char> one;
	vector<pair<char, char> > two ;
	
	void DFS(int n, string str){
		if(n == 0) output.push_back(str);
		if(n%2 == 1) {
			for(int i =0; i<one.size() ; i++) {
				char ch = one[i];
				string ch_s;
				char ch2[2]={ch,0};
				ch_s = ch2;
				DFS(n-1, ch2);			
			}  
			
		}
		if(n%2 == 1) return;
		for(int i = (n==2)? 1: 0; i<two.size(); i++) DFS(n-2, two[i].first + str + two[i].second);
	}
	
public:
	vector<string> findStrobogrammatic(int n) {
		one.push_back('0');
		one.push_back('1');
		one.push_back('8');
		two.push_back(make_pair('0','0'));
		two.push_back(make_pair('1','1'));
		two.push_back(make_pair('8','8'));
		two.push_back(make_pair('6','9'));
		two.push_back(make_pair('9','6'));
		string tmp;
		if(n == 0) {
			output.push_back("");
			return output;
		}
		DFS(n,"");
		return output;
        
    }
};

*/
class Solution {
private:
	string tmp;
	vector<string> output;
	const char ch1[5] = {'0', '1', '8', '6', '9'};
	const char ch2[5] = {'0', '1', '8', '9', '6'};
	void DFS(int a, int b){  //a is the left of tmp, b is the right of tmp
		if(a==b){
			for(int i =0; i<3; i++){
				//if(i != 0 && (a!=0 && b>0)) continue; //ignore 0 in the first pos
				tmp[a] = ch1[i];
				output.push_back(tmp);
			}
		}
		else if(a > b) output.push_back(tmp);
		else{
			for(int i = 0; i<5; i++){
				if(i == 0 && a == 0) continue;
				tmp[a] = ch1[i];
				tmp[b] = ch2[i];
				DFS(a+1, b-1);
			}
		}
	}
public:
	vector<string> findStrobogrammatic(int n) {
		tmp.resize(n);
		if(n == 0) {
			output.push_back("");
			return output;
		}
		DFS(0, n-1);
		return output;
        
    }
};

int main(){
	int n;
	cin >> n;
	vector<string> res;
	Solution sol;
	res = sol.findStrobogrammatic(n);
	for(int i=0; i<res.size(); i++)
	{
		cout << res[i] << " ";
	}
	return 0;
}


