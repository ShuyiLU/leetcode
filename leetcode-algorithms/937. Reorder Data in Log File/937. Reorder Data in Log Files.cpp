class Solution {
public:
    vector<string> reorderLogFiles(vector<string>& logs) {
        vector<int> word, digit;
        map<string, vector<string> > mp;
		for(int i = 0; i<logs.size(); i++){
			string tmp = logs[i];
			int p;
			for(int j=0; j<tmp.size(); j++){
				if(tmp[j] == ' ') {
					p = j;
					break;
				}
			}
			if(tmp[p+1]>='0' && tmp[p+1] <='9') digit.push_back(i);
			else {
              // word.push_back(i); 
               mp[tmp.substr(p+1, tmp.length()-p-1)].push_back(logs[i]);
            }
		}
		vector<string> res;
		map<string, vector<string> > :: iterator it;
		for(it = mp.begin(); it!= mp.end(); it++){
            if((*it).second.size()!= 1) sort((*it).second.begin(), (*it).second.end());
			for(int i=0; i<(*it).second.size(); i++){
				res.push_back((*it).second[i]);
			}	
		}
	 
		for(int i=0; i<digit.size(); i++) res.push_back(logs[digit[i]]);
		return res;
    }
};
