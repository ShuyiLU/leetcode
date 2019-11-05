
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
            if(start <= intervals[i][0]) // ���ظ�
            {
                cnt++;
                start = intervals[i][1]; //̰�ģ����غ�ѡ��һ���Ľ�β
            }
            else{
                start = min(start, intervals[i][1]);  //�غ�ѡ������Ľ�β
            }
        }
        return intervals.size()-cnt;
    }
};
