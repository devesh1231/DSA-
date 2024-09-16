class Solution {
public:
int f(int i,int j,vector<vector<int>>&mat,vector<vector<int>>&dp)
{

     if(i<0||j<0)
    return 0;
    if(mat[i][j]==1)
    return 0;
    if(i==0&&j==0)
    return 1;
    if(dp[i][j]!=-1)
    return dp[i][j];
    int left=f(i-1,j,mat,dp);
    int right=f(i,j-1,mat,dp);
    return dp[i][j]=left+right;
}
    int uniquePathsWithObstacles(vector<vector<int>>& ob) {
        int m=ob.size();
        int n=ob[0].size();
        vector<vector<int>>dp(m,vector<int>(n,-1));
        return f(m-1,n-1,ob,dp);
    }
};