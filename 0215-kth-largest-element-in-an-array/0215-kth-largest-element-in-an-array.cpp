class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> pq;
        for(auto i:nums) pq.push(i);
        int ans=0;
        while(!pq.empty()) {
            auto elem = pq.top();
            pq.pop();
            if(k==1)  ans=elem;
             k--;
        }
        return ans;
    }
};