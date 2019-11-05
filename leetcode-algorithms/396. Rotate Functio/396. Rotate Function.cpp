class Solution {
public:
    int maxRotateFunction(vector<int>& A) {
        if(A.size() == 0) return 0;
        int n = A.size();
        vector<long long> F(A.size(), 0);
        vector<long long> sum(A.size(), 0);
        sum[0] = A[0];
        for(int i=1; i<n; i++) sum[i] = sum[i-1] + A[i];
        for(int i=0; i<A.size(); i++) F[0] += i * A[i];
        //cout << F[0] << endl;
        long long res = F[0];
        for(int i=1; i<A.size(); i++){
            F[i] = F[i-1] + sum[n-i-1] + sum[n-1] - sum[n-i] - (n-1) * A[n-i];
            res = max(res, F[i]);
           // cout << F[i] << endl;
        }
        return res;
        
    }

    
};
