#include<iostream>
#include<map>
#include<set>
#include<vector>

using namespace std;

class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        int count = 0;
        set<string> tmp;
        string s1, s2;
        s2 = "";
        for(int i=0; i<emails.size(); i++){
        	s1 = emails[i];
        	int flag1 = 0; //0: before @  1 :after @
        	int flag2 = 0; //0: before +  1: after +
        	for(int j=0; j<s1.length(); j++){
        		if(s1[j] == '@') flag1 = 1;
        		if(s1[j] == '+') flag2 = 1;
        		if(flag1 == 0 && flag2 == 1) continue;
        		if(flag1 == 1) s2 = s2 + s1[j];
        		if(flag1 == 0){
        			if(s1[j] == '.')continue;
        			else s2 = s2 + s1[j];
				}
			}
		//	cout << s2 << endl;
			tmp.insert(s2);
			s2 = "";
		}
		count = tmp.size();
		return count;
    }
};

int main(){
	int n;
	cin >> n;
	string st;
	vector<string> v;
	for(int i=0; i<n; i++){
		cin >> st;
		v.push_back(st);
	}
	Solution solution;
	cout << solution.numUniqueEmails(v) << endl;
}
