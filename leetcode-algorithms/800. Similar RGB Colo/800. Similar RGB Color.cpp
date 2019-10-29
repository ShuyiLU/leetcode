#include<iostream>
#include<string>

using namespace std;

class Solution {
public:
    string similarRGB(string color) {
    	string res;
    	res.resize(7);
    	res[0] = '#';
    	int tmp = 0;
    	int cha[3];
    	int max[3];
        for(int i=0; i<3; i++){
        	tmp = 0;
        	for(int k=1; k<=2 ; k++){ 
        		if(color[k+i*2] < 'a')  tmp = tmp *16 + int (color[k+i*2] - '0');
				else tmp = tmp *16 + int (color[k+i*2] - 'a' ) + 10 ;
				//cout << tmp << endl; 
			}     	       	        	       	
        	max[i] = -1 * tmp * tmp ;
        	cha[i] = 0;
        	for(int j=0; j<=15; j++){
        		if(-1 * (tmp - (j*16 + j)) * (tmp - (j*16 + j)) > max [i] ){
        			max[i] = -1 * (tmp - (j*16 + j)) * (tmp - (j*16 + j));
        			cha[i] = j;
				}	
			}
		}
		for(int i=0; i<3; i++){
			if(cha[i] <= 9){
				res[1+i*2] = char(cha[i] + '0');
				res[2+i*2] = char(cha[i] + '0');
			}
			else{
				res[1+i*2] = char(cha[i] - 10 + 'a');
				res[2+i*2] = char(cha[i] - 10 + 'a');
			}
		}
		return res;
    }
}; 

int main(){
	string c;
	cin >> c;
	Solution sol;
	cout << sol.similarRGB(c) << endl;
	return 0;
}
