// Forward declaration of the knows API.
bool knows(int a, int b);

class Solution {
public:
    int findCelebrity(int n) {
		int cel = 0;
        for(int i=1; i<n; i++){
			if(!knows(i, cel)) cel = i; //更新证明i以前一定有人不认识i，因此i以前不可能有cel
		}
		
		for(int i=0; i<n; i++){
			if( i!= cel && knows(cel, i) || !knows(i, cel)) return -1;
		}
		return cel;
    }
};
