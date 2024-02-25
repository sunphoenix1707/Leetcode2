class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        for(int i=0;i<nums.size();i++)  {
           
            if(nums[i]>=1 && nums[i]<=nums.size()) {
                 int element = nums[i];
                  int chair=element-1;
            if(nums[chair]!=element)  { swap(nums[chair],nums[i]);
                                       i--;
                                      }
            }
            
            /* Taking [3,4,-1,1] element=3 chair = 2 Is nums[2]==element ,no , swap(3,-1)
            array looks like [-1,4,3,1]  i-- again checking first element at right position or             not element = -1 so here element is not positive simply i++ element = 4 chair =3
             swap(4,1) [-1,1,3,4] now i-- element = 1 chair = 0 , swap(1,-1) arr [1,-1,3,4]
             */
        }
        //checking element is present at right position if not return element
        
        for(int i=0;i<nums.size();i++) {
            if(i+1!=nums[i])  return i+1;
        }
        return n+1;  
        //for case[1,2,3,4,5] here we need to return 6
    } 
};