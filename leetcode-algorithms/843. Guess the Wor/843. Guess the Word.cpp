/**
 * // This is the Master's API interface.
 * // You should not implement it, or speculate about its implementation
 * class Master {
 *   public:
 *     int guess(string word);
 * };
 */
class Solution {
//�²����ֺ�secretƥ���λ��= secret�Ͳ²������ƥ���λ��
//֪���ղµ����ֺ�secret�ж���λƥ�䣬��list�Ͳ²�λ��ƥ��=guess�����Ĳ��п�����secret
//�Ӷ����ݡ�
public:
    void findSecretWord(vector<string>& wordlist, Master& master) { 
		int count = 10;
		while(count--){
            string target = wordlist[random() % wordlist.size()]; // ���ѡ��list������ֽ��в²�
			int matches = master.guess(target);  //��ǰѡ��������ж���λ������
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
