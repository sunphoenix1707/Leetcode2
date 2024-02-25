class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        map<int,int>mp;
        int start=0,end=0;
        for(int i=0;i<trips.size();i++)
        {
             start = trips[i][1];
             end = trips[i][2];
            mp[start] += trips[i][0];
            mp[end]   -= trips[i][0];
        }
        int sum = 0;
        for(auto it=mp.begin();it!=mp.end();it++)
        {
            sum += it->second;
            if(sum > capacity)  return false;
        }
        return true;
    }
};