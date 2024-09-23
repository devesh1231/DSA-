class Solution {
public:

  void merge(vector<int>&arr, int l, int m, int r)
    {
      vector<int>temp;
      int left=l;
      int right=m+1;
      int i=0;
      while(left<=m&&right<=r)
      {
          if(arr[left]<=arr[right])
          {
         temp.push_back(arr[left]);
          left++;
          i++;
          }
          else
          {
          temp.push_back(arr[right]);
          i++;
          right++;
          }
      }
        while(left<=m)
      {
          
          temp.push_back(arr[left]);
          left++;
          i++;
      }
        while(right<=r)
      {
         
          temp.push_back(arr[right]);
          i++;
          right++;
          
      }
      
      for(int i=l;i<=r;i++)
      {
          arr[i]=temp[i-l];
      }
    }
    public:
    void mergeSort(vector<int>&arr, int l, int r)
    {
       if(l>=r)
       return ;
       int mid=(l+r)/2;
       mergeSort(arr,l,mid);
       mergeSort(arr,mid+1,r);
       merge(arr,l,mid,r);
       
    }
    vector<int> sortArray(vector<int>& nums) {
        mergeSort(nums,0,nums.size()-1);
        return nums;
    }
};