class Logger {
public:
    /** Initialize your data structure here. */
    Logger() {
        
    }
    
    /** Returns true if the message should be printed in the given timestamp, otherwise returns false.
        If this method returns false, the message will not be printed.
        The timestamp is in seconds granularity. */
    bool shouldPrintMessage(int timestamp, string message) {
        if(mp.count(message) == 0){
        	mp[message] = timestamp;
        	return true;
        }
        else{
        	if(timestamp-mp[message]>=10){
        		mp[message] = timestamp;
        		return true;
        	}
        	else return false;
        }
    }

    map<string, int> mp;
};
