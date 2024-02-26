class NumArray {
public:
    vector<int> nums;
    vector<int> preffix;
    NumArray(vector<int>& nums) {
        this->nums=nums;
        int n = nums.size();
        preffix.resize(n);
        prefixcalculator(nums);
    }
    
    int sumRange(int left, int right) { 
       return left-1 >= 0 ? preffix[right]-preffix[left-1] : preffix[right];
    }
    void prefixcalculator(vector<int>& nums) {
        preffix[0] = nums[0];
        for(int i=1;i<nums.size();i++)
        {
          preffix[i] += preffix[i-1]+nums[i];
            
        }
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */