class Solution {
public:
    int findMaxK(vector<int>& nums) {
        
          int maxi=0;
        map<int,int>mp;
        int ans=0;
        for(int i=0; i<nums.size();i++) {
            mp[nums[i]]++;
        }
        for(int i=0;i<nums.size();i++)  {
             maxi = max(maxi , nums[i]);
            cout<<"maxi="<<maxi<<endl;
            if(mp.find(-(maxi))!=mp.end())   {
                ans=max(ans,maxi);
                cout<<"ans"<<ans;
            }
            else maxi=0;
            
        }
         if(ans)  return ans;
        else return -1;
        //dikkat [14,33,40,-33,8,-24,-42,30,-18,-34]
    }
};