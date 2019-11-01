int work(vector<int>& A) {
    int ans=0, cnt=0;
    for (int i=0; i<A.size(); i++) {
        if (!i||(i%2==0&&A[i-1]<A[i])||(i%2==1&&A[i-1]>A[i])) ++cnt;
        else {
            ans=max(ans, cnt); cnt=1;
        }
    }
    ans=max(ans, cnt);
    return ans;
}

class Solution {
public:
    int maxTurbulenceSize(vector<int>& A) {
        int ans=0;
        ans=max(ans, work(A));
        for (int& i: A) i=-i;
        ans=max(ans, work(A));
        return ans;
    }
};
