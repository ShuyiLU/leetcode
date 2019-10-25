#include<iostream>
#include<map>

using namespace std;

class Solution {
public:
    bool isHappy(int n) {
    	if(n==1) return true;
        int temp = n;
        int digit = 0;
        int sum = 0;
        map<int, int> mp;
        while(sum != 1){
        	int sum = 0;
        	while(temp != 0){
        		sum = sum + (temp%10) * (temp%10);
        		temp = temp/10;
			}
			if(sum == 1) return true;
			
			if(mp.count(sum) > 0) return false;
			else{
				mp[sum] = 1;
				temp = sum;
			}
		}      
		return false;
    }
};

int main(){
	int n;
	cin >> n;
	Solution sol;
	if(sol.isHappy(n)) cout << "true" << endl;
	else cout << "false" << endl;
}
