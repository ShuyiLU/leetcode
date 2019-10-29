#include<iostream>
#include<algorithm>
#include<cstring>

using namespace std;

class Solution {
public:
    int rotatedDigits(int N) {
        int temp;
        int count = 0;
        int yu, sh;
        int flag1, flag;
        int digit = 0;
        int arr[5];
        memset(arr,0,sizeof(arr));
        for(int i=1; i<=N; i++){
        	digit = 0;
        //	flag1 = 0;
        	flag = 0;
        	temp = i;
        	int k = temp;
        	while(k!=0){
        		yu = k%10;
        		sh = k/10;
        		k = sh;
        		arr[digit] = yu;
        		digit++;
			}
			
			for(int j=0; j<digit; j++){
				if(arr[j]==0 || arr[j]==1 || arr[j]==8) {
				//	flag1 = 1;
					continue;
				}
				else if(arr[j]== 2 || arr[j]== 5 || arr[j]== 6 || arr[j]== 9){
					flag = 1;
					continue;
				}
				else{
					flag = 0;
					break;
				}
			}
		//	for(int c=0; c<digit; c++){
		//		cout << digit << ":" << arr[c] << endl;
		//	} 
		//	cout << flag << endl;
			memset(arr,0,sizeof(arr));
			if(flag == 1) count++;		      
		}
		return count;
    }
};

int main(){
	int N;
	cin >> N;
	Solution sol;
	cout << sol.rotatedDigits(N) << endl;
	return 0;
}
