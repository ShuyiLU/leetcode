class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        map<int, int> mp; // (pos, cnt)
		if(wall.size() == 0) return 0;
		for(int i=0; i<wall.size(); i++){
			int pos = 0;
			for(int j=0; j<wall[i].size()-1; j++){
				pos += wall[i][j];
				mp[pos]++;
			}
		}
		map<int, int> :: iterator it;
		int cnt = 0;
		for(it=mp.begin(); it!=mp.end(); it++){
			if(it->second > cnt) cnt = it->second;
		}
		int res = wall.size()-cnt;
		return res;
    }
};