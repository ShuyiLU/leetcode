#include<iostream>
#include<cstring>
#include<cmath>

using namespace std;

class Solution {
public:
	#define INT_MAX 2147483647
    #define INT_MIN (-INT_MAX-1)
    int reverse(int x) {
    	/* 
    	int cat = x;
    	cat = cat * 10;
    	cat = cat / 10;
    	if(x!= cat) return 0;
    	*/
        if(x >=0 && x<=9) return x;
        long long ans = 0;
        long long tem = abs(x);
        int flag = 0;
        while(tem!=0){
        	
        	//int cat = ans;
        	//cout << cat << " " <<ans << endl;
        	ans = ans*10;
        	ans += tem%10;
        	if((INT_MIN/10>ans)||(INT_MAX/10<ans)) return 0;
        	tem = tem/10;
		}
		if(x < 0) ans = ans * -1;
		/*	
		if(ans<-INT_MIN||ans>INT_MAX ){
           	ans=0;//Òç³öÅÐ¶Ï
       	}
     //  	cout << ans << endl;
     */
		return (int)ans;
		      
    }	
};

int main(){
	int a;
	cin >> a;
	Solution sol;
	cout << sol.reverse(a) << endl;
}
