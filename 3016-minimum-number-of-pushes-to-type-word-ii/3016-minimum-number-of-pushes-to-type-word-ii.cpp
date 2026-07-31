class Solution {
public:
    int minimumPushes(string word) {
        vector <int> arr(26,0);
        for(auto it:word)
        {
          arr[it-'a']++;
        }
        sort(arr.begin(),arr.end(),greater<int>());
        int sum=0;
        for(int i=0;i<26;i++)
        {
            if(i<=7)
            sum+=arr[i];
            else if(i<=15)
            sum+=arr[i]*2;
            else if(i<=23)
            sum+=arr[i]*3;
            else sum+=arr[i]*4;
        }
        return sum;
    }
};