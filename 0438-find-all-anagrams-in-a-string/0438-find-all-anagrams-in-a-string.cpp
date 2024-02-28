class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int n = s.size();
        int m = p.size();
        if(m > n) return {};
        vector<int> ans;
        vector<int> big(26,0);
        vector<int> small(26,0);
        for(int i=0 ; i<m ;i++) {
            big[s[i]-'a']++;
            small[p[i]-'a']++;
        }
        if(big == small) ans.push_back(0);
        
        for(int i=m; i<n;i++) {
            big[s[i-m]-'a']--;
            big[s[i]-'a']++;
            
            if(big == small) ans.push_back(i-m+1);
        }
        return ans;
    }
};