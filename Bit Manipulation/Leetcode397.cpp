class Solution {
public:
    int integerReplacement(int n) {
        int count=0;
        if(n==INT_MAX)
            return 32;
        while(n!=1){
            if((n&1)==0)
                n=n>>1;
            else if(n==3||((n>>1)&1)==0)
                n--;
            else
                n++;
            count++;
        }
        return count;
    }
};
