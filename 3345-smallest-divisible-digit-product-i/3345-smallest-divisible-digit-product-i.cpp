class Solution {
public:
    int smallestNumber(int n, int t) {
        for(int i=n;true;i++)
        {
            int d=i;
            int p=1;
            while(d>0)
            {
                int c=d%10;
                p=p*c;
                d=d/10;
            }
            if(p%t == 0)
            return i;
        }
        return 0;
    }
};