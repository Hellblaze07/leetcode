class Solution {
public:
    unordered_map<int,int> mp;
     int func(long long n)
     {
        if(n == 1)
        return 0;
        if(mp.count(n))
        return mp[n];
        if(n%2 == 0)
        return mp[n]= 1+func(n/2);
        long long first=1+func(n+1);
        long long second=1+func(n-1);
        return mp[n]=min(first,second);
     }
    int integerReplacement(int n) {
       return func(n);
    }
};