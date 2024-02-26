class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string,int> mp;
        for(auto i:words)  mp[i]++;
        vector<pair<string,int>> v;
        for(auto it:mp) {
          v.push_back({it.first,it.second});
        }
        
        auto cmp = [](pair<string,int> &p1, pair<string,int> &p2)
        {
            if(p1.second==p2.second)
                return p1.first < p2.first; //lexicographical order
            
            return p1.second>p2.second;
        };
        
        sort(v.begin(),v.end(),cmp);
        
        int i=0;
        vector<string> ans(k);
        while(i<k) {
            ans[i] = v[i].first;
            i++;
        }
        return ans;
    }
};