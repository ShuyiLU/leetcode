#include<vector>
#include<iostream>
#include<set>

using namespace std; 

class Solution {
public:
    bool canVisitAllRooms(vector<vector<int> >& rooms) {
        set<int> s;
		enter(0, rooms, s);
		if(s.size() == rooms.size()) return true;
		return false;
    }
    
    void enter(int r, vector<vector<int> >& rooms, set<int> &enteredRoom){
    	enteredRoom.insert(r);
    	for(int i=0; i<rooms[r].size(); i++){
    		if(enteredRoom.count(rooms[r][i]) == 0){
    			enter(rooms[r][i], rooms, enteredRoom);
			}	
		}
	}	
	
};
