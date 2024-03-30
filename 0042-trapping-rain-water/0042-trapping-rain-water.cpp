class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int>rmax(n+1,0);
        for(int i=0;i<n;i++) {
             if(i==0)  rmax[i]=height[i];
            else
                rmax[i] = max(rmax[i-1],height[i]);
        }
        vector<int> lmax(n+1,0);
        for(int i=n-1;i>=0;i--)  {
             if(i==n-1)   lmax[i] = height[i];
            else 
                lmax[i] = max(lmax[i+1],height[i]);
        }
        
        int ans=0;
        for(int i=0;i<n;i++) {
            ans+= max(0,min(lmax[i],rmax[i])-height[i]);
        }
        return ans;
    } 
};