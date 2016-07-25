class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int new_len=0,i=0,size=nums.size();
        for(i=0;i<nums.size();i++){
            if(nums[i]!=val){
                nums[new_len++]=nums[i];
            }
        }
        return new_len;
    }
};

