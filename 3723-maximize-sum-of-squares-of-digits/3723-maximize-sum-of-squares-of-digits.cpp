class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        int q=sum/9;
        int rem=sum%9?1:0;
        if(q+rem > num)
        return "";
        string s="";
        for(int i=1;i<=q;i++)
        {
            s+='9';
        }
        if(rem != 0)
        s.push_back(char((sum%9)+'0'));
        int x=s.size();
        while(x<num)
        {
            s.push_back('0');
            x++;
        }
        return s;
    }
};