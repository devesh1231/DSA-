class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
      //  set<vector<int>>st;
       vector<vector<int>>ans;
        for(int i=0;i<nums.size();i++)
        {
            if(i>0&&nums[i]==nums[i-1])
            continue;
            int j=i+1;
            int k=nums.size()-1;

            while(j<k)
            {
            int sum=nums[i]+nums[j]+nums[k];
            if(sum==0)
            {
                ans.push_back({nums[i],nums[j],nums[k]});
                j++;
                k--;
                 while (j < k && nums[j] == nums[j-1]) j++;
                    
                    // Skip duplicate values for +the third element
                while (j < k && nums[k] == nums[k+1]) k--;
            }
            else if(sum<0)
            j++;
            else
            k--;
            }
        }
       
        // for(auto x:st)
        // ans.push_back(x);
        return ans;
    }
};