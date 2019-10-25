#include<iostream>
#include<cstring>
#include<algorithm>
#include<cmath>

using namespace std;




class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
    	int record[26];
    	memset(record, 0, sizeof(record))
		for(int i=0; i<tasks.size; i++){
			record[int(tasks[i]-'0') - 17] ++ ;
		}
		
			
    }
};


int main(){
	char a;
	cin >> a;
	cout << int (a -'0') - 17 << endl;
	
}
