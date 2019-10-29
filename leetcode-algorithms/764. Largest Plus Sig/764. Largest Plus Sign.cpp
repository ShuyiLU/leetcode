#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int orderOfLargestPlusSign(int N, vector<vector<int> >& mines) {
        vector<vector<int> > m(N, vector<int>(N, INT_MAX));
        //set<pair<int, int> > s;
        
		for(int i=0; i<mines.size(); i++){
		//	s.insert(make_pair(mines[i][0], mines[i][1]));
			m[mines[i][0]][mines[i][1]] = 0;
		}
		for(int i=0; i<N; i++){
			if(m[i][0] > 0) m[i][0] = 1;
			if(m[i][N-1] > 0) m[i][N-1] = 1;
		}
		for(int i=0; i<N; i++){
			if(m[0][i] > 0) m[0][i] = 1;
			if(m[N-1][i] > 0) m[N-1][i] = 1;
		}
		
		for(int i=1; i<N; i++){
			for(int j=0; j<N; j++){
				if(m[i][j] == 0) continue;
				else m[i][j] = min(m[i-1][j]+1, m[i][j]);
			}			
		}
		
		for(int i=0; i<N; i++){
			for(int j=1; j<N; j++){
				if(m[i][j] == 0) continue;
				else m[i][j] = min(m[i][j-1]+1, m[i][j]);
			}
		}
		
		for(int i=N-2; i>=0; i--){
			for(int j=N-1; j>=0; j--){
				if(m[i][j] == 0) continue;
				else m[i][j] = min(m[i+1][j]+1, m[i][j]);
			}	
		}
		
		for(int i=N-1; i>=0; i--){
			for(int j=N-2; j>=0; j--){
				if(m[i][j] == 0) continue;
				else m[i][j] = min(m[i][j+1]+1, m[i][j]);
			}			
		}
		
		int res = 0;
		for(int i=0; i<N; i++){
			for(int j=0; j<N; j++){
				if(m[i][j] > res) res = m[i][j];
			}
		}
		return res;	
    }
};

