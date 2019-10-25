#include<iostream>
#include<string>
#include<vector> 
#include<algorithm>

using namespace std;


	

class Solution {
private:
	struct Relation{
		int pos;
		string so;
		string ta;
		Relation(){};
		Relation(int a, string b, string c){
			pos = a;
			so = b; 
			ta = c;
		}
		bool operator<( const Relation& ot ) const {
			return this->pos < ot.pos;
		}
	};
public:
    string findReplaceString(string S, vector<int>& indexes, vector<string>& sources, vector<string>& targets) {
        vector<string> tmp;
        if(indexes.empty()) return S;
        vector<Relation> r; 
        for(int k=0; k<indexes.size(); k++){
        	r.push_back(Relation(indexes[k], sources[k], targets[k])); 
		}
		sort(r.begin(), r.end());
        string res = "";
        int i = 0;
        int j = 0;
        while(i<S.length()){	
        	while(j<indexes.size()){
				if( i < r[j].pos) {
					char c_tmp[2] = {S[i],0};
					tmp.push_back(c_tmp);
					i++;
				}
				else if(i == r[j].pos){
					int c = i;
					int flag = 0;
					for(int d=0; d<r[j].so.length(); d++){
						if(S[c] != r[j].so[d]){
							flag = 1;
							break;
						}
						c++;
					}
					if(flag == 0){
						int len = r[j].so.length();
						tmp.push_back(r[j].ta);
						i = i + len;
						j++;
					}
					else{
						char c_tmp[2] = {S[i],0};
						tmp.push_back(c_tmp);
						j++;
						i++;
					}
					
				/*	if(S[i] == r[j].so[0]){
						int len = r[j].so.length();
						tmp.push_back(r[j].ta);
						i = i + len;
						j++;
					}
					else{
							char c_tmp[2] = {S[i],0};
							tmp.push_back(c_tmp);
							j++;
							i++;
					} */
				}
			}
			
				char c_tmp[2] = {S[i],0};
				tmp.push_back(c_tmp);
				i++;
			
        }
        for(int k =0; k<tmp.size(); k++){
        	res = res + tmp[k];
        }
        return res;
    }
};

int main(){
	string s;
	cin >> s;
	int n;
	cin >> n;
	int p;
	string s1, t1;
	vector<int> pos;
	vector<string> source;
	vector<string> target;
	for(int i=0; i<n; i++){
		cin >> p >> s1 >> t1;
		pos.push_back(p);
		source.push_back(s1);
		target.push_back(t1);
	}
	Solution sol;
	cout << sol.findReplaceString(s,pos,source,target) << endl;
	return 0;
}

