class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size()<3)
            return nums.size();
        int new_len=1,size=nums.size(),i=0;
        for(i=2;i<size;i++){
            if(nums[i]!=nums[new_len-1])
                nums[++new_len]=nums[i];
        }
        return new_len+1;
    }
};
