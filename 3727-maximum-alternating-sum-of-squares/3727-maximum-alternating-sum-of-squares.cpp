class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        sort(nums.begin(),nums.end(),[&](int a,int b) {
            return abs(a) > abs(b);
        });
        int i=0,n=nums.size()-1;
        long long sum1=0,sum2=0;
        int j=1;
        while(j<=nums.size())
        {
            if(j&1)
            {
                sum1+=(1LL*nums[i]*nums[i]);
                i++;
            }
            else {
                sum2+=(1LL*nums[n]*nums[n]);
                n--;
            }
            j++;
        }
        return sum1-sum2;
    }
};