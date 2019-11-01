class Solution {
public:
    int totalFruit(vector<int>& tree) {
        map<int, int> mp;   //mp[i] = i.count
        int i = 0;
        int cnt = 0;
        int ans = -1;
        for(int j=0; j<tree.size(); j++){
        	if(mp[tree[j]] == 0){
        		mp[tree[j]] = 1;
        		cnt++;
        	}
        	else mp[tree[j]]++;
         //   cout << cnt << " ";
        	while(cnt>2){
        		mp[tree[i]]--;
        		if(mp[tree[i]] == 0) cnt--;
                i++;
        	}
        	if(ans<0 || ans<j-i+1) ans = j-i+1;
         //   cout << i << " " << j << " " << ans << endl;
        }
        return ans;
    }
};

