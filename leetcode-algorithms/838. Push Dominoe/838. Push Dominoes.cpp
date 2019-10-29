#include<iostream>
#include<vector>
#include<cstring>

using namespace std;
//从连续最短的.序列找左右两端
//左右两端为R, L, 当前骨牌不变
//左侧为R， 此修改为R
//右侧为L此修改为L
//左右为L, R， 整个序列不变 

class Solution {
public:
    string pushDominoes(string d) {
        
		d = 'L' + d + 'R';
		string res = "";
		int i=0;
		for(int j=1; j<d.length(); j++){
			if(d[j] == '.') continue;
			int middle = j-i-1; // j = R or L , middle=(i, j)之间的距离， 不包括i和j 
			if(i>0) res += d[i];
			if(d[i] == d[j]){
				res += string(middle, d[i]); //该长度内全为	L or R 
			}	
			else if(d[i] == 'L' && d[j] == 'R'){
				res += string(middle, '.');
			}
			else{
				res += string(middle/2, 'R') + string(middle%2, '.') + string(middle/2, 'L');
			}
			i = j;
			//i j为一段连续.的左右两端 
		}
		return res;
    }
};
