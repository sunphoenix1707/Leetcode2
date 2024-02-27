class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<int> dis(n,INT_MAX);
        unordered_map<int,vector<pair<int,int>>> adj;
        for(vector<int> &vec : flights) {
            int u = vec[0];
            int v=vec[1];
            int d=vec[2];
            
            adj[u].push_back({v,d});
        }
         queue<pair<int,int>> q;
         q.push({src,0});
        dis[src]=0;
        int level=0;
        while(!q.empty() && level<=k)  {
            int n = q.size(); 
            while(n--)  {
                 int u = q.front().first;
                 int d= q.front().second;
                q.pop();
                 for(pair<int,int> &p : adj[u]) {
                     int v = p.first;
                     int cost=p.second;
                     if(dis[v] > d+cost) {
                         q.push({v,d+cost});
                         dis[v] = d+cost;
                     }
                 }
            }
            level++;
        }
        return (dis[dst]==INT_MAX) ? -1 : dis[dst];
    }
};