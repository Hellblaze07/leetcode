class Solution {
public:
    int stoneGameVI(vector<int>& aliceValues, vector<int>& bobValues) {
       vector <pair<int,int>> pr;
       int n=aliceValues.size();
       for(int i=0;i<n;i++)
       pr.push_back({aliceValues[i]+bobValues[i],i});
       sort(pr.begin(),pr.end(),greater<pair<int,int>>());
       int c=0;
       for(int i=0;i<n;i++)
       {
        if(i&1)
        {
          c-=bobValues[pr[i].second];
        }
        else c+=aliceValues[pr[i].second];
       }
       if(c>0)
       return 1;
       else if(c<0)
       return -1;
       else return 0;
    }
};