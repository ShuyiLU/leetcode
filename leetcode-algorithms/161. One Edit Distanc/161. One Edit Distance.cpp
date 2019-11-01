class Solution {
public:
    bool isOneEditDistance(string s, string t) {
        if (s.size()>t.size()) swap(s, t);
        int n=s.size(), m=t.size();
        if (n==m) {
            bool ok=false;
            for (int i=0; i<n; i++) {
                if (s[i]!=t[i]) {
                    if (!ok) ok=true;
                    else return false;
                }
            }
            return ok;
        }
        else if (m-n>1) return false;
        // add delete
        bool ok=false;
        for (int i=0; i<n; i++) {
            if (!ok) {
                if (s[i]!=t[i]) {
                    ok=true; i--;
                }
            }
            else if (s[i]!=t[i+1]) return false;
        }
        return true;
    }
};