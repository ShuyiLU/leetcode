#include<iostream>
#include<vector>
#include<cstring>
#include<queue>
#include<set>

using namespace std;

class SnakeGame {
public:
	int w_s, h_s;
	int w, h;
	queue<vector<int> >q;  //food
	int res = 0;
	queue<vector<int> >s_len;  //snake length 
	set<vector<int> > st;
	
    /** Initialize your data structure here.
        @param width - screen width
        @param height - screen height 
        @param food - A list of food positions
        E.g food = [[1,1], [1,0]] means the first food is positioned at [1,1], the second is at [1,0]. */
    SnakeGame(int width, int height, vector<vector<int> >& food) {
        w_s = 0;
        h_s = 0;
        w = width;
        h = height;
        for(int i=0; i<food.size(); i++) q.push(food[i]);
        
        vector<int> tmp;
        tmp.push_back(h_s);
        tmp.push_back(w_s);
        s_len.push(tmp);
        st.insert(tmp);
    }
    
    /** Moves the snake.
        @param direction - 'U' = Up, 'L' = Left, 'R' = Right, 'D' = Down 
        @return The game's score after the move. Return -1 if game over. 
        Game over when snake crosses the screen boundary or bites its body. */
    int move(string direction) {
        if(direction == "U") h_s--;
        else if(direction == "D") h_s++;
        else if(direction == "R") w_s++;
        else if(direction == "L") w_s--;
        
        
        if(h_s < 0 || w_s < 0 || h_s >= h || w_s >= w) return -1;
        if(q.empty()) return res;
        
        vector<int> tmp;
        tmp.push_back(h_s);
        tmp.push_back(w_s);    
       
     
		if(h_s == q.front()[0] && w_s == q.front()[1]){  //get food
        	res++;
        	s_len.push(tmp);
        	st.insert(tmp);
        	q.pop();
		}
		else{
			vector<int> fr = s_len.front();
			s_len.push(tmp);	
			s_len.pop();
			set<vector<int> > :: iterator it;
			it = st.find(fr);
			st.erase(it);			
			if(st.count(tmp) > 0) return -1;
			else{
				st.insert(tmp);
			}
		} 
			
        return res;
    }
};
