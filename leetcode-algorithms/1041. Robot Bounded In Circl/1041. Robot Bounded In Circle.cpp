#include<iostream>
#include<cstring>

using namespace std;


class Solution {
public:
    bool isRobotBounded(string instructions) {
        int dir = 1;
        int x=0, y=0;
        for(int i=0; i<instructions.size(); i++){
        	char c = instructions[i];
        	if(c=='L'){
        		if(dir == 1) dir = 4;
        		else dir -= 1;
			}
			
			else if(c == 'R'){
				if(dir == 4) dir = 1;
				else dir += 1;
			}
			
			else if(c == 'G'){
				if(dir == 1) y++;
				else if(dir == 2) x++
				else if(dir == 3) y--;
				else x--;
			}
		}
		
		if(dir == 1){
			if(x == 0 && y == 0) return true;
			else return false;
		}
		return true;
		
    }
};
