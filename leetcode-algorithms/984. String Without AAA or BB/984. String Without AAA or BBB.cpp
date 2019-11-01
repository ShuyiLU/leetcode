class Solution {
public:
    string strWithout3a3b(int A, int B) {
        string ans;
        while (A>0||B>0) {
            // cout << A << ' ' << B << endl;
            if (A>B) {
                if (A>=2) {
                    ans=ans+"aa"; A-=2;    
                } else {
                    ans=ans+"a"; A-=1;    
                }
                
                if (B) {
                    ans+="b"; B--;
                }
            }
            else if (A<B) {
                if (B>=2) {
                    ans=ans+"bb"; B-=2;
                }
                else {
                    ans+="b"; B--;
                }
                if (A) {
                    ans+="a"; A--;
                }
            }
            else if (A==B) {
                if (ans.empty()||ans.back()=='a') {
                    ans+="ba";
                }
                else {
                    ans+="ab";
                }
                B--; A--;
            }
        }
        return ans;
    }
};
