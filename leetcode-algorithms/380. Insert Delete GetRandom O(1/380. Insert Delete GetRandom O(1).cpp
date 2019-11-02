class RandomizedSet {
public:
    /** Initialize your data structure here. */
   vector<int> v;
    map<int, int> mp;
    RandomizedSet() {
        v.clear();
        mp.clear();
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if(mp.count(val) > 0 ) return false;
        v.push_back(val);
        mp[val] = v.size()-1;
        return true;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if(mp.count(val) == 0) return false;
        int p = mp[val];
        swap(v[p], v[v.size()-1]);
        mp[v[p]] = p;
        mp.erase(v[v.size()-1]);
        v.pop_back();
        return true;
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        if(v.size() == 0) return -1;
        return v[rand() % v.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
