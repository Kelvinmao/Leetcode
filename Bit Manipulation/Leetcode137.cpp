class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int bit[32]={0},res=0;
        for(int i=0;i<32;i++){
            for(int j=0;j<nums.size();j++){
                if((nums[j]>>i)&1)
                    bit[i]++;
            }
            if(bit[i]%3)
                res+=(bit[i]%3)<<i;
        }
        return res;
    }
};
