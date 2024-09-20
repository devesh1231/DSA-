class Solution {
public:
  vector<vector<int>> dp;
int help(vector<vector<int>>& grid,int i,int j)
{
    if(i==0&&j==0)
    {
        return grid[i][j];
    }
    if(i<0||j<0)
    return 1e9;
    if(dp[i][j]!=-1)
    return dp[i][j];
    int x=grid[i][j]+help(grid,i-1,j);
     int y=grid[i][j]+help(grid,i,j-1);
     return dp[i][j]=min(x,y);
}
    int minPathSum(vector<vector<int>>& grid) {
          int m = grid.size();
        int n = grid[0].size();
          dp = vector<vector<int>>(m, vector<int>(n, -1));
        return help(grid,grid.size()-1,grid[0].size()-1);
    }
};