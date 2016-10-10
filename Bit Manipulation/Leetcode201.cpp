class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        int count=0;
        while(m!=n){
            count++;
            m=m>>1;
            n=n>>1;
        }
        return m<<count;
    }
};
