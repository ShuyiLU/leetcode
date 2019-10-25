#include<iostream>
#include<vector>

using namespace std;


/*
class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        int n = A.size();
        if(n < 3) return 0;
        
        vector<vector<int> > f;
        f.resize(n);
        for(int i=0; i<n; i++) f[i].resize(n);
        
        int  count = 0;
        
        for(int i=0; i<n; i++){
        	for(int j=0; j<n; j++){
        		if(j<=i) f[i][j] = 0;
        		else if(j == i+1) f[i][j] = 0;
        		else if(j == i+2){
        			if(A[i+1] - A[i] == A[j] - A[i+1]){
        				f[i][j] = 1;
        				count++;
					}
					else f[i][j] = 0;
				}
				else{
					if(f[i][j-1] == 1 && (A[j]-A[j-1] == A[j-1] - A[j-2])) {
						f[i][j] = 1;
						count++;
					}
					else f[i][j] = 0;
				}
			}
		}
        
        return count;
        
    }
};

*/

class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
    	int n = A.size();
    	if(n<3) return 0;
		int tmp = 0;
		int count = 0;
		int i=2;
		while(i<n){
			if(tmp == 0){
				if(A[i]-A[i-1] == A[i-1]-A[i-2]){
					tmp = 3;
					i++;
				}
				else i++;
			}
			else{
				if(A[i]-A[i-1] == A[i-1]-A[i-2]){
					tmp += 1;
					i++;
				}
				else{
					count = count + (tmp-1)*(tmp-2)/2;
					tmp = 0;
					i++;
				}
			}
			
		}
		
		if(tmp!=0) count = count + (tmp-1)*(tmp-2)/2;
		
		return count;
		
		   
    }
};

int main(){
	int n;
	cin >> n;
	vector<int> v;
	int a;
	for(int i=0; i<n; i++){
		cin >> a;
		v.push_back(a);
	}
	Solution sol;
	cout << sol.numberOfArithmeticSlices(v) << endl;
}
