class Solution {
    void reverse(vector<int>& nums,int l,int h) {
        while(l<h) {
            int temp=nums[l];
            nums[l]=nums[h];
            nums[h]=temp;
            l++;
            h--;
        }
        
    }
public:
    void rotate(vector<int>& nums, int k) {
        int n=nums.size();
    //7 6 5 4 3 2 1
    //5 6 7 1 2 3 4
        
        if(k>n) k%=n;
        int l=0;
        int h=n-1;
       reverse(nums,l,h);
        reverse(nums,l,k-1);
        reverse(nums,k,h);
         

    }
};