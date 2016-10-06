class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        int bit[32]={0},res=0;
        int low=0,high=31;
        for(int i=31;i>=0;i--){
            bit[i]=(n&1);
            n=(n>>1);
        }
        while(low<high){
            swap(bit[low],bit[high]);
            low++;
            high--;
        }
        for(int i=0;i<32;i++)
            res+=(bit[i]*pow(2,31-i));
        return res;
    }
};
