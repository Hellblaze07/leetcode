class Solution {
public:
    vector<int> countTasks(vector<int>& tasks, vector<int>& shifts) {
        int n=tasks.size(); 
        vector <long long> presum(n,0);
        presum[0]=tasks[0];
        for(int i=1;i<n;i++)
        presum[i]=presum[i-1]+tasks[i];
        vector <int> ans(shifts.size(),0);
        long long extra=0;
        for(int i=0;i<shifts.size();i++)
        {  int ind=-1;
          int low=0,high=n-1;
          while(low<=high)
          {
            int mid=low+(high-low)/2;
            if(presum[mid] <= shifts[i]+extra)
            {
                ind=mid;
                low=mid+1;
            }
            else high=mid-1;
          }
          if(ind == -1)
          {
            ans[i]=n;
            extra+=shifts[i];
          }
          else if(ind == n-1)
          {
            ans[i]=0;
            extra=0;
          }
          else {
            extra+=shifts[i];
            ans[i]=n-(ind+1);
          }
        }
        return ans;
    }
};