#include<iostream>
#include<cstring>

using namespace std;

class Solution {
public:
    int repeatedStringMatch(string A, string B) {
        int A_len = A.length();
        int B_len = B.length();
        if(A == B) return 1;
        int times;
        int flag;
        string tmp = "";
        if(B_len >= A_len){
        	B_len = B_len + 1;
        	times = B_len / A_len + 2;
	        tmp = "";
	        for(int i=0; i<times; i++){
	        	tmp = tmp + A;
			}
		}
		else{
			B_len = B_len + 1;
			tmp = A + A;
		}
        
		//cout << tmp << endl;
		for(int i=0; i<tmp.length(); i++){
			if(tmp[i] == B[0]){
				flag = 0;
				int j = i;
				int k = 0;
				//cout << B_len << endl;
				for(k=0; k<B_len-1; k++){
					if(tmp[j] == B[k]){
						j++;
					}
					else{
						flag = 1;
						break;
					}
				}
				//cout << flag << endl;
				if(flag == 1) continue;
				else if(flag == 0){
					B_len = B_len - 1;
					int r = i + B_len - 1;
					r = r + 1;
					if(r%A_len == 0){
						int ans = r/A_len;
						return ans; 
					}
					else{
						int ans = r/A_len + 1;
						return ans;
					}
				}
			}
			
		}
		return -1;
    }
};

int main(){
	string A,B;
	cin >> A >> B;
	Solution sol;
	cout << sol.repeatedStringMatch(A,B) << endl;
	return 0;
}
