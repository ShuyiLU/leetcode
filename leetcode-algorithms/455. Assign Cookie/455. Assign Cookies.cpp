#include<iostream>
#include<vector>
#include<algorithm>


using namespace std;

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
		if(g.size() == 0 || s.size() == 0) return 0;
		sort(g.begin(), g.end());
		sort(s.begin(), s.end());
		int count = 0;
		int i=0, j=0;
		while(i<g.size() && j<s.size()){
			while(g[i] > s[j]) {
				j++;
				if(j >= s.size()) return count;
			}
			count++;
			i++;
			j++;
		}
		return count;
    }
};

int main(){
	int n, m;
	cin >> n >> m;
	vector<int> g;
	vector<int> s;
	int a;
	for(int i = 0; i<n; i++){
		cin >> a;
		g.push_back(a);
	}
	
	for(int i = 0; i<m; i++){
		cin >> a;
		s.push_back(a);
	}
	
	Solution sol;
	cout << sol.findContentChildren(g,s) << endl;
	
}
