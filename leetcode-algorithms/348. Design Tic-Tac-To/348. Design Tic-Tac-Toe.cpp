#include<iostream>
#include<vector>

using namespace std;

class TicTacToe {
private:
	vector<int> row_f; //rows for first player
	vector<int> row_s; //rows for second player
	vector<int> col_f;
	vector<int> col_s;
	int dig_f;
	int dig_s;
	int a_dig_f;  // only 1 possibility
	int a_dig_s;
	int n;
public:
    /** Initialize your data structure here. */
    TicTacToe(int size) {
    	n = size;
        row_f.resize(n, 0);
        row_s.resize(n, 0);
        col_f.resize(n, 0);
        col_s.resize(n, 0);
        dig_f = 0;
        dig_s = 0;
        a_dig_f = 0;
        a_dig_s = 0;
    }
    
    /** Player {player} makes a move at ({row}, {col}).
        @param row The row of the board.
        @param col The column of the board.
        @param player The player, can be either 1 or 2.
        @return The current winning condition, can be either:
                0: No one wins.
                1: Player 1 wins.
                2: Player 2 wins. */
    int move(int row, int col, int player) {
        if(player == 1){
        	if(++row_f[row] == n) return 1;
        	else if(++col_f[col] == n) return 1;
        	else if(row == col && ++dig_f == n) return 1;
        	else if(row+col == n-1 && ++a_dig_f == n) return 1;
        	else return 0;
		}
		else{
			if(++row_s[row] == n) return 2;
        	else if(++col_s[col] == n) return 2;
        	else if(row == col && ++dig_s == n) return 2;
        	else if(row+col == n-1 && ++a_dig_s == n) return 2;
        	else return 0;
		}
    }
};

/**
 * Your TicTacToe object will be instantiated and called as such:
 * TicTacToe* obj = new TicTacToe(n);
 * int param_1 = obj->move(row,col,player);
 */
