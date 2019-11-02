class Solution {
public:
    vector<int> father;
    
    int findFa(int x){
        if(x != father[x]) father[x] = findFa(father[x]);
        return father[x];
    }
    
    void merge(int x, int y){
        int fa1 = findFa(x);
        int fa2 = findFa(y);
        if(fa1 != fa2) father[fa1] = fa2;
    }
    
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int> res;
        if(n == 0) return vector<int>{};
        father.resize(n+1, 0);
        for(int i=1; i<=n; i++) father[i] = i;
        for(int i=0; i<edges.size(); i++){
            int p1 = edges[i][0];
            int p2 = edges[i][1];
            if(findFa(p1) == findFa(p2)){
                res = edges[i];
                break;
            }
            merge(p1, p2);
        }
        return res;
        
    }
};
