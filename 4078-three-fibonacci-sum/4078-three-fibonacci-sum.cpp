class Solution {
public:
    bool threeFibonacciSum(int n) {
        int a=0,b=1,c=1;
        int sum=0;
        while(c<n)
        { sum=a+b+c;
         if(sum == n)
         return true;
         a=b;
         int t=c+b;
         b=c;
         c=t;
        }
        return false;
    }
};