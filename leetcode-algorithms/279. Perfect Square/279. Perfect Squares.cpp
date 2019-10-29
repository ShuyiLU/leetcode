#include<iostream>
#include<cmath>
#include<queue>
#include<map>
using namespace std; 

class Solution {
public:
    int numSquares(int n) {
    	if(n == 0) return 1;
		queue<int> q;
		//map<int, int> mp;
		vector<int> mp(n+1,0);		
		q.push(0);
		mp[0] = 0;
		while(!q.empty()){
			int tem = q.front();
			q.pop();
			for(int i=1; tem+i*i <=n; i++){
				if(mp[tem+i*i] == 0) {
					mp[tem+i*i] = mp[tem] + 1;
					q.push(tem+i*i);
				}
				else{
					if(mp[tem] + 1 < mp[tem+i*i]) mp[tem+i*i] = mp[tem] + 1;
				}
			}	
			
		}
		return mp[n];
    }
    
};

int main(){
	int n;
	cin >> n;
	Solution sol;
	sol.numSquares(n);
	cout << sol.numSquares(n) << endl;
//	if(sol.isPerSq(n)) cout << "true" << endl;
//	else cout << "false" << endl;
	//double n = sqrt(13.0) ;
	//cout << n << endl;
}
