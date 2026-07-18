class Solution {
public:
    int numberOfSubstrings(string s) {
        int i=0;
        int n=s.length();
        int arr[3]={-1,-1,-1};
        int count=0;
        while(i<n)
        {
           arr[s[i]-'a']=i;
           if(arr[0] != -1 && arr[1] != -1 && arr[2] != -1)
           {
            count=count+(1+min({arr[0],arr[1],arr[2]}));
           }
           i++;
        }
        return count;
    }
};