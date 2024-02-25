class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        int shift=0;
        while(left!=right)  {
            left=left>>1; //rightshift
            right=right>>1;
            shift++;
        }
        
        return (left<<shift);
    }
};