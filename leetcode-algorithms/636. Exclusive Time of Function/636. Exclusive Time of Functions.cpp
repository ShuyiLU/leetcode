#include<iostream>
#include<vector>
#include<cstring>
#include<map>
#include<stack>

using namespace std; 

struct state{
	int id;
	char ch;
	int t;
	state(int a, char c, int b) : id(a), ch(c), t(b) {}
	
	
};

class Solution {
public:
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        map<int, int> mp;
        if(n==0) return vector<int>{};
        vector<int> res;
       // res.resize(n);
        string tmp="";
        int id = 0;
        int time = 0;
  		int p = 0;
        stack<state*> st;
		int flag = 0;
		state* pre;
		
        for(int j=0; j<logs[0].length(); j++){
        	if(flag==0 && tmp[j]>='0' && tmp[j]<='9'){
        			id = id*10 + (tmp[j]-'0');
				}
			else if(tmp[j]==':'&&tmp[j+1]=='s'){
					p=0;
					flag = 1;
				}
			else if(tmp[j]==':'&&tmp[j+1]=='e'){
					p=1;
					flag=1;
				}
			else if(tmp[j]==':'&&tmp[j+1]>='0'&&tmp[j+1]<='9'){
					flag = 2;
				}
			else if(flag==2){
					time = time*10 + (tmp[j]-'0');
			}
		
		}
		state* s1 = new state(id, 'e', time); 
		if(p==0){
				s1->ch = 's';
			}
		
		st.push(s1);
		pre = st.top();
        cout << pre->id <<" " << pre->ch << " " << pre->t << endl;
		id = 0;
		time = 0;
        flag = 0;
        
        for(int i=1; i<logs.size(); i++){
        	tmp = logs[i];
        	for(int j=0; j<tmp.size(); j++){
        		if(flag==0 && tmp[j]>='0' && tmp[j]<='9'){
        			id = id*10 + (tmp[j]-'0');
				}
				else if(tmp[j]==':'&&tmp[j+1]=='s'){
					p=0;
					flag = 1;
				}
				else if(tmp[j]==':'&&tmp[j+1]=='e'){
					p=1;
					flag = 1;
				}
				else if(tmp[j]==':'&&tmp[j+1]>='0'&&tmp[j+1]<='9'){
					flag = 2;
				}
				else if(flag==2){
					time = time*10 + (tmp[j]-'0');
				}
				else continue;
				
			}
            cout << pre->id <<" " << pre->ch << " " << pre->t << endl;
            
			if(p==0){
				if(pre->ch == 's'){
					mp[pre->id] = mp[pre->id] + (time-pre->t);
				}
				else{
					continue;
				}	
				st.push(new state(id, 's', time));
				pre = st.top();
			}
			
			else if(p==1){
				//pre = st.top();
				
				if(id != pre->id){
					mp[id] = mp[id] + (time - pre->t);
				}
				else{
					mp[id] = mp[id] + (time - pre->t)+1;
				}
				pre = new state(id, 'e', time );
				//mp[id] = mp[id] + (time - pre.second);
				st.pop();
				//pre = st.top();
			}
			tmp = "";
			id = 0;
			time = 0;
            flag = 0;
		}
		
		map<int,int> :: iterator it;
		for(it=mp.begin(); it!=mp.end(); it++){
			res.push_back((*it).second);
		}
		return res;
		
    }
};

int main(){
	
}
