bool cmp(const pair<int, int> &p1, const pair<int, int> &p2){
    if(p1.first == p2.first) return p1.second > p2.second;
	return p1.first<p2.first;
}
class Solution {
public:
    vector<int> partitionLabels(string S) {
        map<char, int> start;
		map<char, int> end;
		vector<pair<int,int>> v;
		for(int i=0; i<S.length(); i++){
			if(start.count(S[i]) == 0) {
                start[S[i]] = i;
			    v.push_back(make_pair(i, 1));
            }
		}
		
		for(int i=S.length(); i>=0; i--){
			if(end.count(S[i]) == 0) {
                end[S[i]] = i;
                v.push_back(make_pair(i,-1));
            }
			
		}
		
		sort(v.begin(), v.end(), cmp);
        /*for(int i=0; i<v.size(); i++){
            cout << v[i].first << " " << v[i].second << endl;
        }
        */
		vector<int> res;
		int l=-1;
		int pt=0;
		for(int i=0; i<v.size(); i++){
			//if(start.count(S[v[i].first]) == 0 || end.count(S[v[i].first]) == 0 ) pt += 0;
			pt += v[i].second;
			
			if(pt == 0){
				res.push_back(v[i].first-l);
				l = v[i].first;
			}
			
		}
        return res;
    }
};

