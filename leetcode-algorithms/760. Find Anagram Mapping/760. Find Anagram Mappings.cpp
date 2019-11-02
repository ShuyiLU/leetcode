class Solution {
public:
    vector<int> anagramMappings(vector<int>& A, vector<int>& B) {
        vector<pair<int, int> > aa, bb;
        vector<int> ans(A.size());
        for (int i=0; i<A.size(); i++) {
            aa.push_back(make_pair(A[i], i));
            bb.push_back(make_pair(B[i], i));
        }
        sort(aa.begin(), aa.end());
        sort(bb.begin(), bb.end());
        for (int i=0; i<A.size(); i++) {
            ans[aa[i].second]=bb[i].second;
        }
        return ans;
    }
};
