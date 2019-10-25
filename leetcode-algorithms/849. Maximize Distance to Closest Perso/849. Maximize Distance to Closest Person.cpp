#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int max = 0;
        int d1,d2;
        int d;
        vector<int> tmp;
        if(seats.empty()) return 0;
        for(int i=0; i<seats.size(); i++){
        	if(seats[i] == 1) tmp.push_back(i);
		}
		int l,r;
		if(tmp.size() == 1){
			if(tmp[0] == 0) max = seats.size()-1; //只有一个1，且在0位置 
			else{ //只有1个1， 比较两端至1的距离 
				d1 = tmp[0] - 0;
				d2 = seats.size()-1 - tmp[0];
				if(d1>d2) max = d1;
				else max = d2;
			}
		}else{
			for(l=0; l<tmp.size()-1; l++){ //l,r两个连续的1的位置 
				r = l + 1;
				for(int k=tmp[l]+1; k<tmp[r]; k++){ //k是l r之间的位置，看距离最近的是l还是r，max是多少 
					d1 = k-tmp[l];
					d2 = tmp[r]-k;
					if(d1<d2) d = d1;
					else d = d2;
					if(d>max) max = d;			
				}
				if(tmp[0] != 0){ //如果第一个1不在首位，比较max和第一个1和0的距离 
					d = tmp[0] - 0;
					if(d>max) max = d; 
				}
				if(tmp[tmp.size()-1] != seats.size()-1){  //如果最后一个1不在末位 
					d = seats.size()-1 - tmp[tmp.size()-1];
					if(d>max) max = d; 
				}
			}	
		}
		
		return max;
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
	cout << sol.maxDistToClosest(v) << endl;
	return 0; 
}
