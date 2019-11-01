class Solution {
public:
    vector<int> sortedSquares(vector<int>& A) {
        vector<int> ans;
        int i=0, j=A.size()-1;
        while (i<=j) {
            if (abs(A[i])<abs(A[j])) {
                ans.push_back(A[j]*A[j]);
                j--;
            }
            else {
                ans.push_back(A[i]*A[i]);
                i++;
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
