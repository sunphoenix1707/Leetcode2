class Solution {
public:
    //4 [[1,3],[1,4],[2,3],[2,4],[4,3]]
    //everyone trust judge and judge doesnot trust anyone
    //basically townjudge se koi outdegree nhi jana chahiye
    // count array starting from element 1 to the element 4
    //-2 -2 3 1
    int findJudge(int n, vector<vector<int>>& trust) {
        if(n==1) return 1;
        int m = trust.size();
        unordered_map<int,int>mp;
        for(int i=0;i<m;i++) {
            mp[trust[i][0]]-=1;
             mp[trust[i][1]]+=1;
        }
        for(auto i:mp) {
            if(i.second==n-1) return i.first;
        }
        return -1;
    }
};