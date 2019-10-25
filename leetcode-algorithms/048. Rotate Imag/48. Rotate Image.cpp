#include<iostream>
#include<vector>

using namespace std; 


class Solution {
public:
    void rotate(vector<vector<int> >& matrix) {
    	int i, j; 
    	int a,b,c,d,e,f;
    	int n = matrix[0].size();
    	int n2 = n;
        for(int k=0; k<n/2;k++){
        	i=k;
        //	for(j = i; j<n-1; j++){
			j=i;
			n2--;
			while(j<n2){
			e = i;
			f = j;		
        	b = matrix[i][j];
        	a = 0;
        	c = i+1;
        	d = j+1;
        	while(c!=e || d!=f){       
			//	cout << i <<" " << j <<" ";		
        		a = matrix[j][n-1-i];  
				matrix[j][n-1-i] = b;
				b = a;      		      		
        		int tmp = i;
        		i = j;
        		j = n-1-tmp;
        		cout << i <<" " << j <<" ";
        		c = i;
        		d = j;
        	//	cout << c << " " << d << " ";
        	//	cout << endl;
			}
			j++;
		}
	//	}
		}
    }
};

int main(){
	vector<int> v1,v2,v3,v4;
	vector<vector<int> > v;
	v1.push_back(1);
	v1.push_back(2);
	v1.push_back(3);
	v1.push_back(10);
	v.push_back(v1);
	v2.push_back(4);
	v2.push_back(5);
	v2.push_back(6);
	v2.push_back(11);
	v.push_back(v2);
	v3.push_back(7);
	v3.push_back(8);
	v3.push_back(9);
	v3.push_back(14);
	v.push_back(v3);
	v4.push_back(15);
	v4.push_back(16);
	v4.push_back(17);
	v4.push_back(18);
	v.push_back(v4);
	Solution sol;
	sol.rotate(v);
	return 0;
}
