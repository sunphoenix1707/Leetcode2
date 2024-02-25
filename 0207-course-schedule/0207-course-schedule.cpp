class Solution {
public:
//     bool canFinish(int n, vector<vector<int>>& prerequisites) {
//         vector<int> adj[n];
//          for(auto it: prerequisites) {
//              adj[it[1]].push_back(it[0]);
//          }
//             vector<int> indegree(n,0);
//         for(int i=0; i<n;i++)
//         {
//             for(auto it: adj[i]) {
//                 indegree[it]++;
//             }
//         }
        
//         queue<int>q;
//         for(int i=0;i<n;i++) {
//             if(indegree[i]==0) q.push(i);
//         }
        
//         vector<int> topo;
//         while(!q.empty()) {
//             int node=q.front();
//             q.pop();
//             topo.push_back(node);
//             for(auto it: adj[node]) {
//                 indegree[it]--;
//                 if(indegree[it]==0) q.push(it);
//             }
//           }
        
//        if(topo.size()==n)  return true;
//     else return false;
//     }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
         int n = numCourses; 
         vector<int> Indegree(n,0);
         queue<int> q;
         vector<int> answer;
         vector<int> adj[n];
         //Converting to adj list
         for(auto it1 : prerequisites ){
                adj[it1[1]].push_back(it1[0]);
         }
         //Initialising the Indegree
         for(int i =0;i<n;i++){
             for(auto it: adj[i]){
                 Indegree[it]++;
             }
         }
         //Initiliasing the sort Inserting node with 0 indegree to queue
         for(int i=0;i<n;i++){
             if(Indegree[i]==0){
                 q.push(i);
             }
         }
         //-------------------------------------
         //Computing the Topological sort
         while(!q.empty()){
               int node = q.front();
               q.pop();
               answer.push_back(node);
               // Checking for the outdegree of that node
               for( auto ite : adj[node]){
                   Indegree[ite]--;  // Indegree should decrease
                   if(Indegree[ite]==0) q.push(ite);
               }
         }
        
    if(answer.size() == n) return true; 
    else return false;
    }
};