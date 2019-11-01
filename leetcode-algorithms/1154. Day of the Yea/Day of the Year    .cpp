class Solution {
public:
    int dayOfYear(string date) {
        int year = (date[0]-'0')*1000 + (date[1]-'0')*100 + (date[2]-'0')*10 + (date[3]-'0');
        int month = (date[5]-'0')*10 + (date[6] - '0');
        int day = (date[8]-'0')*10 + (date[9]-'0');
        map<int,int> mp;
        int ans = 0;
        for(int i=1; i<=12; i++){
            if(i == 1 || i==3 || i==5 || i==7 || i==8 || i==10 || i==12) mp[i] = 31;
            else if(i==4 || i==6 || i==9 || i==11) mp[i] = 30;
            else if(i==2){
                if((0 == year % 4 && 0 != year % 100) || 0 == year % 400) mp[i] = 29;
                else mp[i] = 28;
            }
        }
        for(int i=1; i<month; i++){
            ans += mp[i];
        }
        ans += day;
        return ans;
    }
};
