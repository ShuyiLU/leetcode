#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int flag_f = 0; //5
        int flag_t = 0; //10
        int flag_tw = 0; //20
        
    if(bills.size() == 0) return true;
    for(int i=0; i<bills.size(); i++){
    	if(bills[i] == 5) flag_f++;
    	else if(bills[i] == 10){
    		if(flag_f == 0) return false;
    		else{
    			flag_f--;
    			flag_t++;
			}
		} 
		else{
			if(flag_f < 3 && flag_t == 0) return false;
			else if(flag_f == 0) return false;
			else{
				if(flag_t > 0){
					flag_t --;
					flag_f --;
				}
				else flag_f -= 3;
				flag_tw ++;
			}
		}
	}
	
	return true;
    }
};

int main(){
	int n;
	cin >> n;
	int a;
	vector<int> v;
	for(int i=0; i<n; i++){
		cin >> a;
		v.push_back(a);
	}
	Solution sol;
	if(sol.lemonadeChange(v)) cout << "true" << endl;
	else cout << "false" << endl;
}
