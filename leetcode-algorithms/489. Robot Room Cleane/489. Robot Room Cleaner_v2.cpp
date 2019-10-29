#include<isotream>
#include<vector>
#include<cstring>
#include<set>


using namespace std;

class Solution {
public:
    void cleanRoom(Robot& robot) {
        set<pair<int, int> > s;
        dfs(0, 0, 0, s, robot);
    }
    
    void dfs(int i, int j, int dir, set<pair<int, int>> visited, Robot& r){
    	if(visited.count(make_pair(i, j)) > 0) return;
    	visited.insert(make_pair(i, j));
    	r.clean();
    	for(int i=0; i<4; i++){
    		if(r.move()){
    			int x = i, int y = j;
    			if(dir == 0) x += 1;
    			if(dir == 1) x -= 1;
    			if(dir == 2) y += 1;
    			if(dir == 3) y -= 1;
    			dfs(x, y, dir, visited, r);  // kepp dfs in one dir until blocked
    			r.turnLeft;
    			r.turnLeft;
    			r.move();
				r.turnLeft;
				r.turnLeft; //return to first start point
			}
			r.turnLeft; //change 90 degree;
			dir = (dir+1) & 4;
		}
	}
};
