class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int end=1,size=nums.size(),i=0;
        if(size<3)
            return size;
        for(i=2;i<size;i++){
            if(nums[i]!=nums[end-1])
                nums[++end]=nums[i];
        }
        return end+1;
    }
};
