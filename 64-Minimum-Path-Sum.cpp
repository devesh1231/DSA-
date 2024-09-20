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
};//////





//tabulation approchh

class Solution {
public:
    vector<vector<int>> dp;

    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        // Initialize dp array
        dp = vector<vector<int>>(m, vector<int>(n, -1));
        
        // Base case: top-left corner
        dp[0][0] = grid[0][0];
        
        // Fill the first row (can only come from the left)
        for (int j = 1; j < n; j++) {
            dp[0][j] = dp[0][j-1] + grid[0][j];
        }
        
        // Fill the first column (can only come from above)
        for (int i = 1; i < m; i++) {
            dp[i][0] = dp[i-1][0] + grid[i][0];
        }
        
        // Fill the rest of the dp table
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                dp[i][j] = grid[i][j] + min(dp[i-1][j], dp[i][j-1]);
            }
        }

        // Return the minimum path sum at the bottom-right corner
        return dp[m-1][n-1];
    }
};
