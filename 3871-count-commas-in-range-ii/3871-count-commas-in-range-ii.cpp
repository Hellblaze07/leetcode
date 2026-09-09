class Solution {
public:
    long long countCommas(long long n) {
        long long i=n;
        int digits=0;
        while(i>0)
        {
            digits++;i=i/10;
        }
        long long count=0;
        if(digits<=3)
        count=0;
        else if(digits<=6)
        count=n-999;
        else if(digits<=9)
        count=999999-999+(n-999999)*2;
        else if(digits<=12)
        count=999999-999+((999999999-999999)*2)+(n-999999999)*3;
        else count=999999-999+(999999999-999999)*2+(999999999999-999999999)*3+(n-999999999999)*4;
        if(digits == 16)
        count++;
        return count;
    }
};