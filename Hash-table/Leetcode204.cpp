class Solution {
public:
    int countPrimes(int n) {
        int count=0;
        bool isprime[n];
        for(int i=0;i<n;i++)
            isprime[i]=true;
        for(int i=2;i<sqrt(n);i++){
            if(isprime[i]){
                for(int j=2;j*i<n;j++)
                    isprime[j*i]=false;
            }
        }
        for(int i=2;i<n;i++){
            if(isprime[i]==true)
                count++;
        }
        return count;
    }
};
