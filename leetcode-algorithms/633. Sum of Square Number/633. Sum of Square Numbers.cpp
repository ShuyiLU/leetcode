class Solution {
public:
    bool judgeSquareSum(int c) {
        if (!c) return true;
        int root=floor(sqrt(c/2));
        for (int i=0; i<=root&&i*i<=c; i++) {
            int b=floor(sqrt(c-i*i)+0.5);
            if (i*i+b*b==c) return true;
        }
        return false;
    }
};
