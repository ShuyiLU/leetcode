class Solution {
public:
    bool verifyPreorder(vector<int>& preorder) {
        int m=INT_MIN;
        stack<int> s;
        for (int i: preorder) {
            if (i<m) return false;
            while (!s.empty()&&s.top()<i) {
                m=s.top(); s.pop();
            }
            s.push(i);
        } return true;
    }
};