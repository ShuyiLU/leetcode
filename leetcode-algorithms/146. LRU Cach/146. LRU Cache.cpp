class LRUCache {
private: 
    //map<int, pair<int, int> > mp;  //(key, (value, timestamp));
    map<int, int> timestamp;  //(timestamp, key)
    unordered_map<int, int> mp;
    int n = 0;
    int size = 0;
public:
    LRUCache(int capacity) {
        size = capacity;
    }
    
    int get(int key) {
        if( mp.count(key) == 0 ) return -1;
        else{
            n++;
            map<int, int> :: iterator it;
            for(it=timestamp.begin(); it!=timestamp.end(); it++){
                if((*it).second == key){
                    timestamp.erase(it);
                    break;
                }
            }
            timestamp[n] = key;
            return mp[key];
        }
    }
    
    void put(int key, int value) {
        n++;
        if(mp.count(key) > 0){
            mp[key] = value;
            map<int, int> :: iterator it;
            for(it=timestamp.begin(); it!=timestamp.end(); it++){
                if((*it).second == key){
                    timestamp.erase(it);
                    break;
                }
            }           
            timestamp[n] = key;
        }
        else{
            if(mp.size() == size){
                map<int, int> :: iterator it;
                it = timestamp.begin();
                mp.erase((*it).second);
                timestamp.erase(it);
            }
            mp[key] = value;
            timestamp[n] = key;            
        }
    }
};