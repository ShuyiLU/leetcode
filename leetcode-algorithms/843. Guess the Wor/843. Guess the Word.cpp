/**
 * // This is the Master's API interface.
 * // You should not implement it, or speculate about its implementation
 * class Master {
 *   public:
 *     int guess(string word);
 * };
 */
class Solution {
//猜测数字和secret匹配的位数= secret和猜测的数字匹配的位数
//知道刚猜的数字和secret有多少位匹配，则list和猜测位数匹配=guess（）的才有可能是secret
//从而缩容。
public:
    void findSecretWord(vector<string>& wordlist, Master& master) { 
		int count = 10;
		while(count--){
            string target = wordlist[random() % wordlist.size()]; // 随机选择list里的数字进行猜测
			int matches = master.guess(target);  //当前选择的数字有多少位猜中了
            if(matches == -1) continue;
			if(matches == 6) break;
			
			shrinkWordlist(wordlist, target, matches);
		}
    }
	int match(string &a, string &b){
		int ans  = 0;
		for(int i=0; i<a.length(); i++){
			if(a[i] == b[i]) ans++;
		}
		return ans;
	}
	
	void shrinkWordlist(vector<string>& wordlist, string &guessWord, int &matches){
		vector<string> tmp;
		for(int i=0; i<wordlist.size(); i++){
			string str = wordlist[i];
			int m = match(str, guessWord);
			if(m == matches) tmp.push_back(str);
		}
		wordlist = tmp;
	}
};
