class Solution {
public:
    int jump(vector<int>& nums) {
      int jumps =0;
        int l=0;
        int r=0;
        int n = nums.size();
      
        while(r<n-1) {
              int far=0;
            for(int i=l; i<=r;i++) {
                   far = max(far, i+nums[i]);
                  
            }
         l=r+1;
       
         r=far;
              jumps=jumps+1;
        }
        return jumps;
    }
};