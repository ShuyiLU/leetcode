class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int W) {
        if(hand.size() % W != 0) return false;
        map<int, int> mp;
        for(int i=0; i<hand.size(); i++){
        	mp[hand[i]]++;
        }
        map<int, int> :: iterator it;
        for(it=mp.begin(); it!=mp.end(); it++){
        	while(mp[(*it).first] > 0){
        		for(int i=0; i<W; i++){
        			mp[(*it).first+i]--;
        			if(mp[(*it).first+i] < 0) return false;
        		}	
        	}	
        }
        return true;
    }
};
