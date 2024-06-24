class Solution {
public:
    int countHomogenous(string s) {
        int MOD = 1e9 + 7;
        int streak=0;
        int ans=0;
        for(int i=0; i<s.size();i++)  {
            
            if(i==0 || s[i]!=s[i-1]) {
                streak=1;
            }
            else {
                    streak++;
            }
            ans = (ans + streak)%MOD;
        }
        return ans;
    }
};