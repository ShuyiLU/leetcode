class Solution {
public:
    int subarraysDivByK(vector<int>& A, int K) {
        int n = A.size();
		int cnt = 0;
		int sum = 0;
		map<int, int> mp;  //mp[i] = j: sum%k = i, k count
        mp[0] = 1;
		for(int i=0; i<n; i++){
			sum += A[i];
			int t = sum % K;
			cnt += mp[t];
			cnt += mp[t-K];
			cnt += mp[t+K];
			mp[sum%K] += 1;
		}
		
		
		return cnt;
    }
};



