class Solution {
public:
    vector<int> lexicalOrder(int n) {
        priority_queue<string>pq;
        for(int i=1;i<=n;i++)
        {
            string s=to_string(i);
            pq.push(s);
        }
        vector<int>ans(n,-1);
        int j=n-1;
        while(pq.size()>0)
        {
            int x=stoi(pq.top());
            pq.pop();
            ans[j]=x;
            j--;
        }
        return ans;
    }
};