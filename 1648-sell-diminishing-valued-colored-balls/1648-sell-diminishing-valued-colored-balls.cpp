class Solution {
public:
    int maxProfit(vector<int>& inventory, int orders) {
        sort(inventory.rbegin(),inventory.rend());
        inventory.push_back(0);
        long long mod=1e9+7;
        long long largcount=1;
        long long sum=0;
        for(int i=0;i<inventory.size()-1;i++)
        { long long curr=inventory[i];
        long long next=inventory[i+1];
        long long available=(curr-next)*largcount;
        if(available >= orders)
        {
         long long q=(orders/largcount);
         long long rem=orders%largcount;
         long long add=(largcount*(q)*(curr+(curr+1-q))/2)%mod;
         sum=(sum+add)%mod;
         long long lastadd=curr-q;
         sum=(sum+rem*lastadd)%mod;
         return sum;
        }
        else {
            sum=(sum+(curr-next)*(curr+next+1)/2*largcount)%mod;
            orders=orders-available;
            largcount++;
        }
        }
        return sum%mod;
    }
};