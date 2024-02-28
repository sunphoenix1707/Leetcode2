class Solution {
public:
    
    int dfs(vector<vector<int>> &grid , int m ,int n , int i,int j,int &count) {
        if(i<0 || j<0 || i>=n || j>= m || grid[i][j]==0)  return 0;
        //making grid containing one zero to avoid calling same neighbour again
        
     
        grid[i][j] = 0;
           
        if ( dfs(grid,m,n,i+1,j,count)) count++;
        if ( dfs(grid,m,n,i-1,j,count)) count++;
        if ( dfs(grid,m,n,i,j+1,count)) count++;
        if ( dfs(grid,m,n,i,j-1,count)) count++;
        
        return 1;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int count = 0;
        int maxi=0;
        for(int i=0 ; i<n ;i++) {
            for(int j=0; j<m ;j++) {
                if(grid[i][j]==1) {
                    int count=1; //resetting count =0 for every dfs call
                    dfs(grid,m,n,i,j, count);
                        maxi=max(maxi , count);
                }
            }
        }
        return maxi;
    }
};