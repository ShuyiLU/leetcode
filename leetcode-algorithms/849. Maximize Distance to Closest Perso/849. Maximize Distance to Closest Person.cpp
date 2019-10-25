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
			if(tmp[0] == 0) max = seats.size()-1; //ֻ��һ��1������0λ�� 
			else{ //ֻ��1��1�� �Ƚ�������1�ľ��� 
				d1 = tmp[0] - 0;
				d2 = seats.size()-1 - tmp[0];
				if(d1>d2) max = d1;
				else max = d2;
			}
		}else{
			for(l=0; l<tmp.size()-1; l++){ //l,r����������1��λ�� 
				r = l + 1;
				for(int k=tmp[l]+1; k<tmp[r]; k++){ //k��l r֮���λ�ã��������������l����r��max�Ƕ��� 
					d1 = k-tmp[l];
					d2 = tmp[r]-k;
					if(d1<d2) d = d1;
					else d = d2;
					if(d>max) max = d;			
				}
				if(tmp[0] != 0){ //�����һ��1������λ���Ƚ�max�͵�һ��1��0�ľ��� 
					d = tmp[0] - 0;
					if(d>max) max = d; 
				}
				if(tmp[tmp.size()-1] != seats.size()-1){  //������һ��1����ĩλ 
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
