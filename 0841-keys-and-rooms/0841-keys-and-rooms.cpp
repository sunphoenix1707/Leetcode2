class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<bool>visited(n,false);
        queue<int> q;
        q.push(0);
        visited[0]=true;
        while(!q.empty()) {
            int e = q.front();
            q.pop();
            for(auto it : rooms[e]) {
                if(!visited[it]) {
                    visited[it]=true;
                     q.push(it);
                }
            }
        }
        
        for(auto x: visited)  {
            if(!x) return false;
        }
        return true;
    }
};