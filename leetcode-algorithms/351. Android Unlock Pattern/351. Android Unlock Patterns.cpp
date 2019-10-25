#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    vector<bool> visited;
    vector<vector<int>> hash; // crossing numbers
   // int cnt;
    int numberOfPatterns(int m, int n) {
        visited.resize(10, false);
        hash.resize(10, vector<int>(10, 0));
        visited[0] = true;
        
        hash[1][9] = hash[9][1] = hash[3][7] = hash[7][3] =  5;
		hash[4][6] = hash[6][4] = hash[2][8] = hash[8][2] = 5;
		hash[1][7] = hash[7][1] = 4;
		hash[1][3] = hash[3][1] = 2;
		hash[3][9] = hash[9][3] = 6;
		hash[7][9] = hash[9][7] = 8;
        
       
        return DFS(m, n, 1, 1)*4 + DFS(m, n, 1, 2)*4 + DFS(m, n, 1, 5);     
    }
    
    int DFS(int m, int n, int len, int start){
        int cnt = 0;
        if(len >= m) cnt++;
        if(len == n) return cnt;
        visited[start] = true;
        for(int i=1; i<=9; i++){
            if(visited[i] == false && visited[hash[start][i]] == true){
                cnt += DFS(m, n, len+1, i);
            }
        }
        
        visited[start] = false;
        return cnt;
    }
    
    
};
