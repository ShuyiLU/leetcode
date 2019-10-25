class Solution {
private: 
    int fa[1001];
    int findUnion(int k){
	    if(fa[k] == -1) return k;
	    else return fa[k] = findUnion(fa[k]);
    }

    void merge_pt(int a, int b){
	    int fa1 = findUnion(a);
	    int fa2 = findUnion(b);
	    if(fa1!=fa2){
		    fa[fa1] = fa2;
	    }
    }
    
public:
    int removeStones(vector<vector<int>>& stones) {
        memset(fa,-1 , sizeof(fa));
    	if(stones.size() <=1) return 0;
        int count = stones.size();
        for(int i=0; i<stones.size(); i++){
        	for(int j=i+1; j<stones.size(); j++){
        		if(stones[i][0] == stones[j][0] || stones[i][1] == stones[j][1]){
        			merge_pt(i, j);
				}
			}
		}
		for(int i=0; i<stones.size(); i++){
			if(fa[i] == -1) count--;
		}
		return count;
    }
};
