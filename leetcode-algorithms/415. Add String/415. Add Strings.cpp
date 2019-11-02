class Solution {
public:
    string addStrings(string num1, string num2) {
        if (num1=="0"&&num2=="0") return "0";
        int carry=0, n1=num1.size(), n2=num2.size();
        int n=max(n1, n2);
        string ans;
        for (int i=0; i<n; i++) {
            int a=i<n1?(num1[n1-1-i]-'0'):0;
            int b=i<n2?(num2[n2-1-i]-'0'):0;
            carry+=a+b;
            ans.push_back('0'+carry%10);
            carry/=10;
        }
        if (carry) ans.push_back('0'+carry);
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
