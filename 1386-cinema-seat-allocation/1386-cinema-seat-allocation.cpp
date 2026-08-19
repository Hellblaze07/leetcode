class Solution {
public:
    int maxNumberOfFamilies(int m, vector<vector<int>>& res) {
        sort(res.begin(),res.end());
        int curr=0;
        int ans=0;
        int n=res.size();
        for(int i=0;i<n;)
        {
            if(res[i][0]-curr > 1)
            {
                ans=ans+(res[i][0]-curr-1)*2;
            }
            if(res[i][0] != curr)
            curr=res[i][0];
            int arr[3]={0};
            while(i<n && res[i][0] == curr)
            {
                if(res[i][1] == 1 || res[i][1] == 10)
                {
                    i++;
                    continue;
                }
                if(res[i][1] == 2 || res[i][1] == 3)
                {
                  arr[0]=1;
                }
              else if(res[i][1] >= 4 && res[i][1] <= 5)
                {   arr[0]=1;
                    arr[1]=1;
                }
                else if(res[i][1] == 6 || res[i][1] == 7)
                {
                    arr[1]=1;
                    arr[2]=1;
                }
              else if(res[i][1] == 8 || res[i][1] == 9)
                {
                    arr[2]=1;
                }
                i++;
            }
            if(arr[0] == 0)
            ans++;
            if(arr[2] == 0)
            ans++;
            if(arr[0] == 1 && arr[2] == 1 && arr[1] == 0)
            ans++;    
        }
        if(m > curr)
        ans=ans+(m-curr)*2;
        return ans;
    }
};