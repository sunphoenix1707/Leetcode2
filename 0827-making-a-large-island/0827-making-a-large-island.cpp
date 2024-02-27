class Solution {
public:
    bool checkvalid(int i,int j,int m,int n) {
        if(i<0 || j<0 || i>=n || j>=m) return false;
        
        return true;
    }
    void dfs(int id,int i,int j,vector<vector<int>> &grid,int m,int n,int &count)
    {
        if(i<0 || j<0 || i>=n || j>=m) return;
        else if(grid[i][j] > 1 || grid[i][j]==0) return; //already visited call else for grid==1
        else {
            grid[i][j]=id;
            dfs(id,i+1,j,grid,m,n,count);
            dfs(id,i-1,j,grid,m,n,count);
            dfs(id,i,j+1,grid,m,n,count);
            dfs(id,i,j-1,grid,m,n,count);
            count++;
        }
        
    }
    int largestIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        map<int,int>mp;
        int id=2;
        int maxi=INT_MIN;
        for(int i=0;i<n;i++) {
            for(int j=0; j<m;j++) {
                if(grid[i][j]==1)
                {
                    int count = 0;
                    dfs(id,i,j,grid,m,n,count);
                    mp.insert({id,count});
                    id++;
                }
            }
        }
        //change 0 to 1
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(grid[i][j]==0) 
                {
                    int sum=0;
                    set<int> s;
                    //checkvalid checks if the neighbour is valid or not
                    //grid[i-1][j]>1 this is for checking id > 1 grid[i][j]=0 neighbour should be greator than one
                    
            //last it should not be inside the set because we only want the unique values
        if(checkvalid(i-1,j,m,n) && grid[i-1][j]>1 && s.find(grid[i-1][j])==s.end())
        {
            s.insert(grid[i-1][j]);
            auto it=mp.find(grid[i-1][j]);
            sum+=it->second;
        }
        if(checkvalid(i+1,j,m,n) && grid[i+1][j]>1 && s.find(grid[i+1][j])==s.end())
        {
            s.insert(grid[i+1][j]);
            auto it=mp.find(grid[i+1][j]);
            sum+=it->second;
        }

        if(checkvalid(i,j-1,m,n) && grid[i][j-1]>1 && s.find(grid[i][j-1])==s.end())
        {
            s.insert(grid[i][j-1]);
            auto it=mp.find(grid[i][j-1]);
            sum+=it->second;
        }

        if(checkvalid(i,j+1,m,n) && grid[i][j+1]>1 && s.find(grid[i][j+1])==s.end())
        {
            s.insert(grid[i][j+1]);
            auto it=mp.find(grid[i][j+1]);
            sum+=it->second;
        }
         maxi = max(maxi,sum+1);
                }
            }
        }
        return (maxi==INT_MIN)?m*n : maxi;
    }
};