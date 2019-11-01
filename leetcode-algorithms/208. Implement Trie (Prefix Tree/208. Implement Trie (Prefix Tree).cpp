class Trie {
private:
    set<string> s;
    set<string> :: iterator it;
public:
    /** Initialize your data structure here. */
    Trie() {
        
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        s.insert(word);
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        return s.count(word);
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        if(s.count(prefix)) return true;
        else{
            int n = prefix.length();
            int flag = 0;
            for(it = s.begin(); it != s.end(); it++){
                flag = 0;
                for(int i=0; i<n; i++){
                    if((*it)[i] != prefix[i]) break;
                    else flag++;
                }
                if(flag == n) return true;
            }
            return false;
        }
    }
};
