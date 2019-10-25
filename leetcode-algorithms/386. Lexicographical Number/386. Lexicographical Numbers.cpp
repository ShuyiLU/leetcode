#include<vector>

using namespace std;

class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int> res;
        for(int i=1; i<10; i++){
        	dfs(i, n, res); //(1, 10, 1XX, 2, 3,3XX, 4)
		}
		return res;
    }
    
    void dfs(int cur, int n, vector<int> &res){
    	if(cur > n) return;
    	else{
    		res.push_back(cur);
    		for(int i=0; i<10; i++){
    			if(10*cur + i > n) continue;
    			else{
    				dfs(10*cur+i, n, res);  //10, 101, 102; 11, 110, 111; **
				}
			}
		}
	}
    
};
