#include<iostream>
#include<cstring>
#include<stack>

using namespace std;


class Solution {
public:
    string addBinary(string a, string b) {
        int len1 = a.length();
        int len2 = b.length();
        stack<int> st;
        while(!st.empty()) st.pop();
        int i = len1-1;
        int j = len2-1;
        long long k=0, ne=0;
        while(i>=0 || j>=0){
        	int re = (i >= 0 ? a[i]-'0' : 0) + (j >= 0 ? b[j]-'0' : 0) + ne;
        	ne = 0;
        	if(re < 2) {
				st.push(re);
			}
			else{
				ne = 1;
				if(re == 2) st.push(0);
				else st.push(1);
					
			}
			i--;
			j--;
        	
		}
		if(ne > 0) {
			st.push(1);
		//	k++;
		}
        string sum_r;
        k = st.size();
        sum_r.resize(k);
        int c = 0;        
        while(!st.empty()){
        	sum_r[c] = char (st.top() + '0');
        	c++;
        	k--;
        	st.pop();
		}
        return sum_r;
    }
};


int main(){
	string a,b;
	cin >> a >> b;
	Solution sol;
	string c = sol.addBinary(a,b);
	cout << c << endl;
}
