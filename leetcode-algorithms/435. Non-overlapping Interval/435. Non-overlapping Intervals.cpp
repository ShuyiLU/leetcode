
bool cmp(vector<int> &v1, vector<int> &v2){
    if(v1[1] == v2[1]) return v1[0]<v2[0];
    return v1[1] < v2[1];
}

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if(intervals.size() <= 1) return 0;
        sort(intervals.begin(), intervals.end(), cmp);
        int cnt = 1;
        int start = intervals[0][1];
        for(int i=1; i<intervals.size(); i++){
            if(start <= intervals[i][0]) // 不重复
            {
                cnt++;
                start = intervals[i][1]; //贪心，不重合选下一个的结尾
            }
            else{
                start = min(start, intervals[i][1]);  //重合选早结束的结尾
            }
        }
        return intervals.size()-cnt;
    }
};
