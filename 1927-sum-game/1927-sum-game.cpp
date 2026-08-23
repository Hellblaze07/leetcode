class Solution {
public:
    bool sumGame(string s) {
        int n=s.size();
        int sum1=0,space1=0;
        for(int i=0;i<n/2;i++)
        {
          if(s[i] == '?')
          space1++;
          else sum1=sum1+(s[i]-'0');
        }
        for(int i=n/2;i<n;i++)
        {
          if(s[i] == '?')
          space1--;
          else sum1=sum1-(s[i]-'0');
        }
        if(space1 & 1)
        return true;
        if(space1 == 0 && sum1 == 0)
        return false;
        else if(sum1 != 0 && space1 == 0)
        return true;
        else if(sum1 >= 0 && space1 > 0)
        {
           return true;
        }
        else if(sum1 <= 0 && space1 < 0)
        return true;
        else 
        {   space1=abs(space1);
            sum1=abs(sum1);
            int mini =space1/2*9;
            int maxi=space1/2*9+(space1%2)*9;
            if(mini < sum1 || maxi > sum1)
            return true;
            else return false;
        }
    }
};