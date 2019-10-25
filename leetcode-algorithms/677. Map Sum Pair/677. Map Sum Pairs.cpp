#include<iostream>
#include<vector>

using namespace std;
/*
class MapSum {
public:
     Initialize your data structure here. 
    map<string, int> mp;
    MapSum() {
        
    }
    
    void insert(string key, int val) {
        mp[string] = val;
    }
    
    int sum(string prefix) {
        int s = 0;
        map<string, int> :: iterator it;
        for(it = mp.begin(); it!=mp.end(); it++){
        	string tmp = (*it).first;
        	int flag = 0;
        	for(int i=0; i<prefix.length(); i++){
        		if(prefix[i] != tmp[i]) {
					flag = 1;
					break;
				}
			}
			if(flag == 0) sum = sum + (*it).second;
			
		}
		return sum;
    }
};
*/

class MapSum {
public:
    /** Initialize your data structure here. */
    MapSum() {
        
    }
    
    void insert(string key, int val) {
        int inc = val;
        Trie *p = &root;
        for(const char c: key){
        	if( p->children[c] == NULL ){
        		p->children[c] = new Trie();
			}
			p->children[c]->s += inc;  //每个节点寸当前值+key 
			p = p->children; //下一层 （下一个char） 
		}
		mp[key] = val;
    }
    
    int sum(string prefix) {
        Trie* p = &root;
        for(const char c:prefix){
        	if( p->children[c] == NULL) return 0;
        	p = p->children[c];
		}
		return p->s;
    }
    
private:
	struct Trie{
		Trie() : children(128, NULL), sum(0) {}
		~Trie(){
			for(auto child : children){
				if(child) delete child;
			children.clear();
			}		
		}
		vector<Trie*> children;
		int s;
	}
	
	Trie root;
	map<string, int> mp;
    
    
};












