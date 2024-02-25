class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        int n = num.size();
        int carry=0;
        for(int i=n-1; i>=0 ;i--) {
            int sum = num[i]+carry+k%10;
            num[i]=sum%10;
            carry=sum/10;
            k=k/10;
            if(k==0 && carry==0) break;
        }
        
        while(k)  {
            int val = k%10 + carry;
            k=k/10;
            num.insert(num.begin(), val%10);
            carry=val/10;
           
        } 
         if(carry) {
                num.insert(num.begin(),carry);
            }
        return num;
    }
};