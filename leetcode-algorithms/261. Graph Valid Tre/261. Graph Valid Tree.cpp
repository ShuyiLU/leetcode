class Solution {
public:
    vector<int> father;
    int findFa(int x){
        if(x != father[x]) father[x] = findFa(father[x]);
        return father[x];
    }
    
    void merge(int x, int y){
        int fa_x = findFa(x);
        int fa_y = findFa(y);
        if(fa_x != fa_y) father[fa_y] = fa_x;
    }
    
    
    bool validTree(int n, vector<vector<int>>& edges) {
        father.resize(n);
        for(int i=0; i<n; i++) father[i] = i;
        int k = edges.size();
        if(k != n-1) return false;
        for(int i=0; i<k; i++){
            int p1 = edges[i][0];
            int p2 = edges[i][1];
            if(findFa(p1) != findFa(p2)){
                merge(p1, p2);
                n--;
            }
            else return false;
        }
        if(n == 1) return true;
        else return false;
    }
};