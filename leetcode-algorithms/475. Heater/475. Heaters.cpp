#include<iostream>
#include<set>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        int radius;
        sort(houses.begin(), houses.end());
        sort(heaters.begin(), heaters.end());
        vector<int> r_k;
        for(int i=0; i<houses.size(); i++){
        	int flag = 0;
        	int pos;   // = nearHeater(houses[i]);
        	int l = 0;
			int r = heaters.size()-1;
			int mid = (l+r) / 2;
			while(abs(mid-l) >= 1 && abs(mid-r) >= 1){
				if(houses[i] < heaters[mid]){
					r = mid;
				}
				else if(houses[i] > heaters[mid]){
					l = mid;
				}
				else{
					pos = heaters[mid];
					flag = 1;
					break;
				}	
				mid = (l+r)/2;		
			}
			if(flag == 0 && (abs(mid-l) < 1 || abs(mid-r) < 1)){
				if(abs(houses[i]-heaters[l]) < abs(houses[i]-heaters[r]) ) pos = heaters[l];
				else pos = heaters[r];
			}
		//	cout << i << ": " << pos << endl;
			int r1 = abs(pos - houses[i]);
        	r_k.push_back(r1);
		}
		for(int i=0; i<r_k.size(); i++){
		//	cout << i << ":" << r_k[i] << endl;
		}
		sort(r_k.begin(), r_k.end());
		radius = r_k[r_k.size()-1];
		return radius;
    }
};

int main(){
	int n, m;
	cin >> n >> m;
	int a,b;
	vector<int> v1;
	vector<int> v2;
	for(int i=0; i<n; i++){
		cin >> a;
		v1.push_back(a);	
	}
	for(int i=0; i<m; i++){
		cin >> b;
		v2.push_back(b);	
	}
	Solution sol;
	cout << sol.findRadius(v1, v2) << endl;
	return 0;
}
