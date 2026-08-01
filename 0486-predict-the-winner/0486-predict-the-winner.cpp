class Solution {
public:
  bool func(int i,int j,vector<int>& nums,int sum1,int sum2,int chance)
  {
    if(i>j)
    {
      if(sum1>=sum2)
      return true;
      else return false;
    }
    if(chance)
    {
      if(func(i+1,j,nums,sum1+nums[i],sum2,!chance) || func(i,j-1,nums,sum1+nums[j],sum2,!chance))
      return true;
    }
    else {
     if(func(i+1,j,nums,sum1,sum2+nums[i],!chance) && func(i,j-1,nums,sum1,sum2+nums[j],!chance))
      return true;
    }
    return false;
  }
    bool predictTheWinner(vector<int>& nums) {
        int n=nums.size();
       return func(0,n-1,nums,0,0,1);
    }
};