#include<iostream>
#include<vector>
#include<cstring>

using namespace std;

class Solution {
public:
    string multiply(string num1, string num2) {
    	if(num1 == "0" || num2 == "0") return "0";
    	string ans;
    	int temp[num1.size() + num2.size()];
    	for(int i=0; i<num1.size() + num2.size(); i++) temp[i] = 0;
    //	ans.resize(num1.size() + num2.size());
    //	for(int i=0; i<ans.size(); i++) ans[i] = '0';
    	
    	int k;
        for(int j=num2.size()-1; j>=0; j--){
        	int t1 = 0;
        	int t2 = 0;
        	for(int i=num1.size()-1; i>=0; i--){
        		int tem = (num1[i] -'0') * (num2[j]-'0') + t1;
        		t1 = tem/10;
        		tem = tem%10;
        		int tmp = temp[i+j+1] + tem + t2;
        		temp[i+j+1] = tmp % 10;
        		t2 = tmp/10;
        		
			}
			if(t1 > 0 || t2 > 0) temp[k+j] += t1+t2;
			//t = 0;
		}
		int len = num1.size() + num2.size();
		if(temp[0] == 0) ans.resize(len - 1);
		else ans.resize(len);
		for(int i=ans.length()-1; i>=0; i--) {
			ans[i] = char(temp[len-1] + '0');
			len--;
		}
		return ans;
    }
};

int main(){
	string n1, n2;
	cin >> n1 >> n2;
	Solution sol;
	cout << sol.multiply(n1, n2) << endl;
}
