class Solution {
public:
    int maxScore(vector<int>& card, int k) {
        int n = card.size();
        vector<int> preffix(n);
      
        preffix[0]=card[0];
        for(int i=1;i<n;i++) {
            preffix[i] += card[i]+preffix[i-1];

        }
          if(n==k)  return preffix[n-1];
        for(int i=0;i<preffix.size();i++) {
            cout<<preffix[i]<<" ";
        }
        int maxi=0,ans=0;
        for(int i=0; i<=k ;i++) {
            int j = i+n-k-1;
            if(i==0)  ans=preffix[j];
            else  ans=preffix[j]-preffix[i-1];
            maxi = max(maxi,preffix[n-1]-ans);
        }
        return maxi;
    }
};