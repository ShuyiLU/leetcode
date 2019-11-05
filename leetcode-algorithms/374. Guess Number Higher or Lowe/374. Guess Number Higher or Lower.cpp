// Forward declaration of guess API.
// @param num, your guess
// @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
int guess(int num);

class Solution {
public:
    int guessNumber(int n) {
        int l, r;
		l = 1, r = n;
		
		while(l<=r){
			int mid = (r-l)/2 + l;
			int res = guess(mid);
			if(res==0) return mid;
			else if(res>0) l = mid+1;
			else r = mid-1;
		} 
		return -1;
    }
};
