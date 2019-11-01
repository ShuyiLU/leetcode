const int mod=1e9+7;

class Solution {
public:
    int threeSumMulti(vector<int>& A, int target) {
        int cnt[400]={}, ans=0;
        for (int k=2; k<A.size(); k++) {
            int j=k-1;
            for (int i=0; i<j; i++) cnt[A[i]+A[j]]++;
            if (target>=A[k]) ans=(ans+cnt[target-A[k]])%mod;
        }
        return ans;
    }
};
