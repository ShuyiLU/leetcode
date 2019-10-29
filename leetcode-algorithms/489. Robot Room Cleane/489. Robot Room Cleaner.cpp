#include<iostream>
#include<set>
#include<vector>
#include<cstring>

using namespace std;

class Solution {
private:
	vector<vector<int>> dir(4, vector<int>{});
	for(int i=0; i<4; i++) dir[i].resize(2);
	dir[0][0] = 1;
	dir[0][1] = 0; //(1,0);
	dir[1][0] = -1;
	dir[1][1] = 0; //(-1,0);
	dir[2][0] = 0;
	dir[2][1] = 1; //(0,1);
	dir[3][0] = 0;
	dir[3][1] = -1; //(0,-1);	
	
public:
    void cleanRoom(Robot& robot) {
        set<vector<int> > visited;
        backtrack(robot, visited, 0, 0, 0);
    }
    
    void backtrack(Robot& robot, set<vector<int> > &visited, int x, int y, int arrow){  //(x,y):current cell, arrow: cur_dir
    	vector<int> cell(2, -1);
    	cell[0] = x;
    	cell[1] = y;
    	if(visited.count(cell) > 0) return;
    	visited.insert(cell);
    	robot.clean();
    	
    	for(int i=0; i<4; i++){
    		if(robot.move()){
    			int nx = x+dir[arrow][0];
    			int ny = y+dir[arrow][1];
    			
    			backtrack(robot, visited, nx, ny, arrow);
    			robot.turnLeft();
    			robot.turnLeft();
    			robot.move();
    			robot.turnLeft();
    			robot.turnLeft();
			}
			robot.turnLeft();
			arrow = (arrow+1)%4;
		}
    	
	}
};
