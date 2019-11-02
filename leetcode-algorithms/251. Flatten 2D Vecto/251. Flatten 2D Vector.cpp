class Vector2D {
public:
    Vector2D(vector<vector<int>>& vec2d): vec2d(vec2d) {
        
    }

    int next() {
        return vec2d[i][j];
    }

    bool hasNext() {
        if (vec2d.empty()) return false;
        do {
            j++;
            if (j>=vec2d[i].size()) i++, j=0;
            if (i<vec2d.size()&&j<vec2d[i].size()) return true;
        } while (i<vec2d.size());
        return false;
    }
private:
    int i=0, j=-1;
    vector<vector<int>> vec2d;
};

/**
 * Your Vector2D object will be instantiated and called as such:
 * Vector2D i(vec2d);
 * while (i.hasNext()) cout << i.next();
 */