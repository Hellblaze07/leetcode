class Solution {
public:
    vector<vector<int>> aggregateTimeSeries(vector<vector<int>>& series1, vector<vector<int>>& series2) {
        vector<vector<int>> ans;
        int m=series1.size();
        int n=series2.size();
        int i=0;
        int j=0;
        while(i<m && j<n)
        {
            if(series1[i][0] == series2[j][0])
           { ans.push_back({series1[i][0],series1[i][1]+series2[j][1]});
           i++;j++;
           }
           else if(series1[i][0] < series2[j][0])
           {
            ans.push_back({series1[i][0],series1[i][1]+series2[j][1]});
           i++;
           }
           else {
            ans.push_back({series2[j][0],series1[i][1]+series2[j][1]});
           j++;
           } 
        }
        while(i<m)
        {
            ans.push_back(series1[i]);
            i++;
        }
        while(j<n)
        {
            ans.push_back(series2[j]);
            j++;
        }
        return ans;
    }
};