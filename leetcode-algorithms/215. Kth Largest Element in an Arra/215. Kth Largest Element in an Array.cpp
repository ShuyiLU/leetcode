#include<iostream>
#include<vector>
#include<queue>

using namespace std;

//minheap
class Solution {
private:
	struct cmp{
		bool operator()(int a, int b){
			return a>b;
		}
	};	
	
public:
    int findKthLargest(vector<int>& nums, int k) {
    	int n = nums.size();
    	if(n==0) return 0;
    	
        priority_queue<int, vector<int>, cmp> q;
        
        for(int i=0; i<n; i++){
        	if(q.size() < k) q.push(nums[i]);
        	else{
        		if(nums[i] < q.top()) continue;
        		else{
        			q.pop();
        			q.push(nums[i]);
				}
			}
		}
        
        return q.top();
    }
};



class Solution {
public:
	int partition(vector<int>& nums, int p, int r){
		int x = nums[r];
		int i = p-1;
		for(int j=p; j<r; j++){
			if(nums[j] < x){
				i = i + 1;
				swap(nums[i], nums[j]);
			}
		}
		swap(nums[i+1], nums[r]);
		return i+1;
	}
	int kthOrder(vector<int>& nums, int p, int r, int i){
		if(p<r){
			int q = partition(nums, p, r);
			int k = q-p+1;
		//	for(int j=0; j<nums.size(); j++) cout << nums[j] << endl;
		//	cout << endl;
			if(k == i) return nums[q];
			else if (i < k) return kthOrder(nums, p, q-1, i);
			else return kthOrder(nums, q+1, r, i-k);
		}
		else return -1;
	}
	
    int findKthLargest(vector<int>& nums, int k) {
        return kthOrder(nums, 0, nums.size()-1, nums.size()-k+1);
    }
};


int main(){
	int n;
	cin >> n;
	int a;
	int k;
	cin >> k;
	vector<int> v;
	for(int i=0; i<n; i++){
		cin >> a;
		v.push_back(a);
	}
	Solution sol;
	cout << sol.findKthLargest(v, k) << endl;
}
