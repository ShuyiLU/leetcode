#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;

class Solution {
public:
    string licenseKeyFormatting(const string& S, int K) {
    	int len = 0;
        for(int i=0; i<S.length(); i++){
        	if(S[i] == '-') continue;
        	else {
        		len++;	
			}
		}
		//cout << len << endl;
		if(len == 0) {
			//output = output + "-";
			//output = " ";
			return "";
		}
		string output;
		int fir = len%K;
		int group = len/K;
		int m = 0;
		int c = 0;
		if(fir != 0){
			output.resize(K*group + group + fir);
			//int m = 0;
			for(int i=0; i<fir; i++){
				if(S[m]!='-'){
					//output.push_back(char(S[m]-'a'+'A'));
					//output = output + S[m];
					if(S[m] >= 'a' && S[m] <= 'z') output[c] = char(S[m]-'a'+'A');//output.push_back(char(S[m]-'a'+'A'));//output.append(1,char(S[m]-'a'+'A'));
					else output[c] = S[m];
					//else output = output + S[m];
					c++;
					m++;
				}
				else {
					m++;
					i--;	
				}
			}
			for(int i=0; i<group; i++){
				//output = output + "-";
				output[c] = '-';
				c++;
				for(int j=0; j<K; j++){
					if(S[m]!='-'){
						if(S[m] >= 'a' && S[m] <= 'z') output[c] = char(S[m]-'a'+'A');//output.push_back(char(S[m]-'a'+'A'));//output.append(1,char(S[m]-'a'+'A'));
						else output[c] = S[m];
					//else output = output + S[m];
						c++;
						//output = output + S[m] -'a' + 'A';
						m++;
					}
					else {
						m++;
						j--;	
					}
				}
				
			}
		}
		else{
			output.resize(K*group + group - 1);
		//	cout << output.size() << endl;
			for(int i=0; i<group; i++){
				//output = output + "-";
				for(int j=0; j<K; j++){
					if(S[m]!='-'){
						if(S[m] >= 'a' && S[m] <= 'z') output[c] = char(S[m]-'a'+'A');//output.push_back(char(S[m]-'a'+'A'));//output.append(1,char(S[m]-'a'+'A'));
						else output[c] = S[m];
						c++;
						//output = output + S[m] - 'a' + 'A';
						m++;
					}
					else{
						m++;
						j--;
					} 
				}
				if(i!= group-1) {
					output[c] = '-';
					c++;
				}
			}
		}
		return output;
    }
};

int main(){
	string s;
	int K;
	cin >> s >> K;
	Solution solution;
	cout << solution.licenseKeyFormatting(s, K) << endl; 
}
